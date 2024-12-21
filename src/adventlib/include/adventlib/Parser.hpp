#pragma once

#include <string_view>

namespace sb
{
	struct Sink
	{
	};

	template<typename T> struct Parser
	{
		static constexpr T parse(std::string_view const str);
	};

	template<> struct Parser<char>;
	template<> struct Parser<std::string_view>;
	template<> struct Parser<Sink>;
} // namespace sb

#include "inl/Parser.inl"
