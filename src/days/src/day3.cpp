#include "days.hpp"

#include <adventlib/Parser.hpp>
#include <adventlib/utilities.hpp>

#include <charconv>
#include <optional>

namespace
{
	using value_t = std::uint32_t;

	std::optional<value_t> parse_value(std::string_view str)
	{
		value_t result;
		const auto conv_result = std::from_chars(str.data(), str.data() + str.size(), result);
		if (conv_result.ec != std::errc() || conv_result.ptr != str.data() + str.size())
		{
			return std::nullopt;
		}
		return result;
	}

	struct Operands
	{
		value_t lhs;
		value_t rhs;
	};

	std::optional<Operands> parse_operands(std::string_view str)
	{
		std::size_t const comma_pos = str.find(',', 0);

		if (comma_pos == std::string_view::npos)
		{
			return std::nullopt;
		}

		const std::string_view lhs_str = str.substr(0, comma_pos);
		const std::optional<value_t> lhs_value = parse_value(lhs_str);

		if (!lhs_value)
		{
			return std::nullopt;
		}

		const std::string_view rhs_str = str.substr(comma_pos + 1);
		const std::optional<value_t> rhs_value = parse_value(rhs_str);

		if (!rhs_value)
		{
			return std::nullopt;
		}

		const Operands result{ *lhs_value, *rhs_value };
		return result;
	}

	value_t find_and_execute_muls(std::string_view str)
	{
		constexpr std::string_view MUL_START = "mul(";

		std::size_t cur_pos = 0;
		std::size_t operands_begin = 0;
		std::size_t operands_end = 0;

		auto const load_operands_pos = [&]() -> void
		{
			cur_pos = str.find(MUL_START, cur_pos);

			if (cur_pos == std::string_view::npos)
			{
				return;
			}

			operands_begin = cur_pos + MUL_START.size();
			operands_end = str.find(')', operands_begin);

			if (operands_end == std::string_view::npos)
			{
				cur_pos = std::string_view::npos;
				return;
			}

			cur_pos += MUL_START.size();
		};

		value_t sum = 0;

		for (load_operands_pos(); cur_pos != std::string_view::npos; load_operands_pos())
		{
			std::string_view const operands_str =
				str.substr(operands_begin, operands_end - operands_begin);
			if (std::optional<Operands> operands = parse_operands(operands_str);
				operands.has_value())
			{
				sum += operands->lhs * operands->rhs;
			}
		}

		return sum;
	}
} // namespace

std::string sb::day_3_1(std::string const& input)
{
	const value_t sum = find_and_execute_muls(input);

	return sb::to_string(sum);
}

std::string sb::day_3_2(std::string const& /*input*/)
{
	return "";
}
