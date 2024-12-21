#include "days.hpp"

#include <adventlib/utilities.hpp>

#include <array>
#include <cassert>

namespace
{
	using day_func_t = std::string (*)(std::string const&);

	constexpr std::array<day_func_t, 50> DAYS{
		sb::day_1_1,  sb::day_1_2,  sb::day_2_1,  sb::day_2_2,  sb::day_3_1,  sb::day_3_2,
		sb::day_4_1,  sb::day_4_2,  sb::day_5_1,  sb::day_5_2,  sb::day_6_1,  sb::day_6_2,
		sb::day_7_1,  sb::day_7_2,  sb::day_8_1,  sb::day_8_2,  sb::day_9_1,  sb::day_9_2,
		sb::day_10_1, sb::day_10_2, sb::day_11_1, sb::day_11_2, sb::day_12_1, sb::day_12_2,
		sb::day_13_1, sb::day_13_2, sb::day_14_1, sb::day_14_2, sb::day_15_1, sb::day_15_2,
		sb::day_16_1, sb::day_16_2, sb::day_17_1, sb::day_17_2, sb::day_18_1, sb::day_18_2,
		sb::day_19_1, sb::day_19_2, sb::day_20_1, sb::day_20_2, sb::day_21_1, sb::day_21_2,
		sb::day_22_1, sb::day_22_2, sb::day_23_1, sb::day_23_2, sb::day_24_1, sb::day_24_2,
		sb::day_25_1, sb::day_25_2,
	};

	std::filesystem::path get_resources_path()
	{
		auto current_path = std::filesystem::current_path();
		auto const root_path = current_path.root_path();
		while (true)
		{
			current_path = current_path.parent_path();

			if (current_path == root_path)
			{
				throw std::runtime_error{ "Unable to find resources path" };
			}

			auto resources_path = current_path / "resources";
			if (std::filesystem::exists(resources_path))
			{
				return resources_path;
			}
		}
	}

	std::string get_default_input_path(sb::day_t day)
	{
		static auto const days_path = (get_resources_path() / "days").generic_string();
		return days_path + "/" + std::to_string(day) + ".txt";
	}

	std::string get_test_input_path(sb::day_t day, int variation)
	{
		static auto const tests_path = (get_resources_path() / "tests").generic_string();
		return tests_path + "/" + std::to_string(day) + "_" + std::to_string(variation) + ".txt";
	}
} // namespace

std::string sb::get_test_input(day_t day, int variation)
{
	auto const path{ get_test_input_path(day, variation) };
	return sb::read_all(path.c_str());
}

std::string sb::run_day_with_default_input(day_t day, part_t part)
{
	auto const path{ get_default_input_path(day) };
	auto const input{ sb::read_all(path.c_str()) };
	return sb::run_day(day, part, input);
}

std::string sb::run_day_with_test_input(day_t day, part_t part, int variation)
{
	return sb::run_day(day, part, sb::get_test_input(day, variation));
}

std::string sb::run_day(day_t day, part_t part, std::string const& input)
{
	assert(day >= 1 && day <= 25);
	assert(part >= 1 && part <= 2);

	return DAYS[(day - 1) * 2 + part - 1](input);
}
