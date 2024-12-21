#pragma once

#include "../utilities.hpp"

#include "../Parser.hpp"

#include <algorithm>
#include <cassert>
#include <utility>

SB_FORCE_INLINE void sb::unreachable()
{
#ifdef __GNUC__ // GCC 4.8+, Clang, Intel and other compilers compatible with
				// GCC (-std=c++0x or above)
	__builtin_unreachable();
#elif defined(_MSC_VER) // MSVC
	__assume(false);
#else                   // ???
#error
#endif
	assert(!"unreachable code reached");
}

template<typename T> std::string sb::Serializer<T>::serialize(T const& value)
{
	return std::to_string(value);
}

template<typename T> std::string sb::to_string(T const& value)
{
	return Serializer<T>::serialize(value);
}

template<typename Coll, typename Func> constexpr auto sb::transform(Coll const& coll, Func&& func)
{
	using result_t = std::decay_t<std::invoke_result_t<Func&&, decltype(*coll.cbegin())>>;
	std::vector<result_t> result{};
	result.resize(coll.size());
	std::transform(coll.cbegin(), coll.cend(), result.begin(), std::forward<Func>(func));
	return result;
}

template<bool Enable> void sb::static_unreachable() noexcept
{
	static_assert(Enable, "Unreachable template code");
}

namespace sb::detail
{
	template<typename Delimiter> auto get_delimiter_size(Delimiter& delimiter) noexcept
	{
		using decayed_delim = std::decay_t<Delimiter>;
		if constexpr (std::is_same_v<decayed_delim, char>)
		{
			return 1;
		}
		else if constexpr (std::is_same_v<decayed_delim, std::string_view>)
		{
			return delimiter.size();
		}
		else
		{
			sb::static_unreachable();
		}
	}

	template<typename Delimiter>
	std::string_view::iterator find_next_match(std::string_view::iterator begin,
											   std::string_view::iterator end, Delimiter delimiter)
	{
		if constexpr (std::is_same_v<Delimiter, char>)
		{
			return std::find(begin, end, delimiter);
		}
		else if constexpr (std::is_same_v<Delimiter, std::string_view>)
		{
			assert(!delimiter.empty());
			return std::search(begin, end, delimiter.begin(), delimiter.end());
		}
		else
		{
			sb::static_unreachable();
		}
	}
} // namespace sb::detail

template<sb::EmptySubstringsPolicy Policy, typename Delimiter, typename Func>
void sb::for_each(std::string_view str, Delimiter delimiter, Func&& func)
{
	static_assert(std::is_same_v<std::invoke_result_t<Func&&, std::string_view>, bool>);

	auto str_cur{ str.begin() };
	auto const delimiter_size{ sb::detail::get_delimiter_size(delimiter) };

	for (auto str_end{ sb::detail::find_next_match(str_cur, str.end(), delimiter) };
		 str_end != str.end(); str_cur = std::next(str_end, delimiter_size),
							   str_end = sb::detail::find_next_match(str_cur, str.end(), delimiter))
	{
		std::string_view const substr{ str_cur, str_end };

		if constexpr (Policy == EmptySubstringsPolicy::exclude)
		{
			if (substr.empty())
			{
				continue;
			}
		}

		auto const should_continue{ std::forward<Func>(func)(substr) };
		if (!should_continue)
		{
			return;
		}
	}

	std::string_view const substr{ str_cur, str.end() };

	if constexpr (Policy == EmptySubstringsPolicy::exclude)
	{
		if (substr.empty())
		{
			return;
		}
	}

	std::forward<Func>(func)(substr);
}

std::vector<std::string_view> sb::split(std::string_view str, char delimiter)
{
	std::vector<std::string_view> result{};

	auto const count{ static_cast<unsigned>(std::count(std::begin(str), std::end(str), delimiter) +
											1) };
	result.resize(count);

	auto str_cur{ str.begin() };
	std::string_view::iterator str_end;
	for (std::size_t i{}; i < count - 1; ++i, str_cur = std::next(str_end))
	{
		str_end = sb::detail::find_next_match(str_cur, str.end(), delimiter);
		result.at(i) = std::string_view{ str_cur, str_end };
	}

	result.back() = std::string_view{ str_cur, str.end() };

	return result;
}

std::vector<std::string_view> sb::split(std::string_view str, std::string_view delimiter)
{
	auto const delimiter_size{ sb::detail::get_delimiter_size(delimiter) };

	std::string_view::iterator str_cur{ str.begin() };

	std::vector<std::string_view> result{};

	for (std::string_view::iterator str_end{ std::search(str_cur, str.end(), delimiter.begin(),
														 delimiter.end()) };
		 str_end != str.end();
		 str_cur = std::next(str_end, delimiter_size),
		 str_end = std::search(str_cur, str.end(), delimiter.begin(), delimiter.end()))
	{
		result.push_back(std::string_view{ str_cur, str_end });
	}

	result.push_back(std::string_view{ str_cur, str.end() });

	return result;
}

template<bool FirstRun, typename T, typename... Ts>
constexpr void sb::scan(std::string_view str, std::string_view pattern, T& out, Ts&... outs)
{
	constexpr std::string_view VAR_PATTERN{ "{}" };

	assert(!str.empty());

	if constexpr (FirstRun)
	{
		auto pattern_sink_pos{ std::search(pattern.begin(), pattern.end(), VAR_PATTERN.begin(),
										   VAR_PATTERN.end()) };
		assert(pattern_sink_pos != pattern.end());
		std::string_view const pattern_to_ignore_from_start{ pattern.begin(), pattern_sink_pos };
		auto const str_leftover_begin{ std::next(std::search(str.begin(), str.end(),
															 pattern_to_ignore_from_start.begin(),
															 pattern_to_ignore_from_start.end()),
												 pattern_to_ignore_from_start.size()) };
		std::string_view const str_leftover{ str_leftover_begin, str.end() };
		std::string_view const pattern_leftover{ pattern_sink_pos, pattern.end() };

		scan<false>(str_leftover, pattern_leftover, out, outs...);
		return;
	}
	else if constexpr (!FirstRun)
	{
		assert(std::equal(VAR_PATTERN.begin(), VAR_PATTERN.end(), pattern.begin()));
		if (pattern.size() == 2)
		{
			out = sb::Parser<T>::parse(str);
			return;
		}
		auto const pattern_middle_to_ignore_start{ pattern.begin() + VAR_PATTERN.size() };
		auto const pattern_middle_to_ignore_end{ std::search(pattern_middle_to_ignore_start,
															 pattern.end(), VAR_PATTERN.begin(),
															 VAR_PATTERN.end()) };
		std::string_view const pattern_middle_to_ignore{ pattern_middle_to_ignore_start,
														 pattern_middle_to_ignore_end };
		auto const str_to_parse_end{ std::search(str.begin(), str.end(),
												 pattern_middle_to_ignore.begin(),
												 pattern_middle_to_ignore.end()) };
		std::string_view const str_to_parse{ str.begin(), str_to_parse_end };

		out = sb::Parser<T>::parse(str_to_parse);

		if constexpr (sizeof...(Ts))
		{
			std::string_view const str_leftover{
				std::next(str_to_parse_end, pattern_middle_to_ignore.size()), str.end()
			};
			std::string_view const pattern_leftover{ pattern_middle_to_ignore_end, pattern.end() };

			sb::scan<false>(str_leftover, pattern_leftover, outs...);
		}
	}
}
