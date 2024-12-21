#pragma once

#include "macros.hpp"

#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

namespace sb
{
	/// Tell the compiler we shouldn't get here ever
	[[noreturn]] SB_FORCE_INLINE void unreachable();

	/// Tell the compiler this should never get compiled
	template<bool Enable = false> void static_unreachable() noexcept;

	/// Uses sb::Serializer of defaults to std::to_string
	template<typename T> [[nodiscard]] std::string to_string(T const& value);

	/// Specialize this if you want to sb::to_string compatibility
	template<typename T> struct Serializer
	{
		[[nodiscard]] static std::string serialize(T const& value);
	};

	/// Sugar syntax for std::transform
	template<typename Coll, typename Func>
	[[nodiscard]] constexpr auto transform(Coll const& coll, Func&& func);

	/// \return The content of the file at input_file_path
	[[nodiscard]] std::string read_all(char const* input_file_path);

	enum class EmptySubstringsPolicy
	{
		include,
		exclude,
	};

	/// Calls Func for every string between delimiters. Func must return bool to indicate if
	/// iterations should continue. Guaranteed to call func at least once.
	template<EmptySubstringsPolicy Policy = EmptySubstringsPolicy::include, typename Delimiter,
			 typename Func>
	void for_each(std::string_view str, Delimiter delimiter, Func&& func);

	/// \return Every substring between delimiters. Guaranteed to return at least one string.
	inline std::vector<std::string_view> split(std::string_view str, char delimiter);
	inline std::vector<std::string_view> split(std::string_view str, std::string_view delimiter);

	/// \return Every lines. Line count is guaranteed to be at least 1.
	std::vector<std::string_view> split_lines(std::string_view str);

	/// Poor man's implementation of a Python str scan
	template<bool FirstRun = true, typename T, typename... Ts>
	constexpr void scan(std::string_view str, std::string_view pattern, T& out, Ts&... outs);
} // namespace sb

#include "inl/utilities.inl"
