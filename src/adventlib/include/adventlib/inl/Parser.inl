#pragma once

#include "../Parser.hpp"

#include <cassert>
#include <charconv>

template<typename T> constexpr T sb::Parser<T>::parse(std::string_view str)
{
	T result;
	[[maybe_unused]] const auto conv_result =
		std::from_chars(str.data(), str.data() + str.size(), result);
	assert(conv_result.ec == std::errc());
	return result;
}

template<> struct sb::Parser<char>
{
	static constexpr char parse(std::string_view str)
	{
		assert(str.size() == 1);
		return *str.begin();
	}
};

template<> struct sb::Parser<std::string_view>
{
	static constexpr std::string_view parse(std::string_view str) noexcept
	{
		return str;
	}
};

template<> struct sb::Parser<sb::Sink>
{
	static constexpr sb::Sink parse(std::string_view) noexcept
	{
		return Sink{};
	}
};
