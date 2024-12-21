#pragma once

#include <filesystem>
#include <string>

namespace sb
{
	using day_t = int;
	using part_t = int;

	static constexpr day_t NUM_DAYS = 25;
	static constexpr part_t NUM_PARTS_PER_DAY = 2;

	std::string day_1_1(std::string const& input);
	std::string day_1_2(std::string const& input);
	std::string day_2_1(std::string const& input);
	std::string day_2_2(std::string const& input);
	std::string day_3_1(std::string const& input);
	std::string day_3_2(std::string const& input);
	std::string day_4_1(std::string const& input);
	std::string day_4_2(std::string const& input);
	std::string day_5_1(std::string const& input);
	std::string day_5_2(std::string const& input);
	std::string day_6_1(std::string const& input);
	std::string day_6_2(std::string const& input);
	std::string day_7_1(std::string const& input);
	std::string day_7_2(std::string const& input);
	std::string day_8_1(std::string const& input);
	std::string day_8_2(std::string const& input);
	std::string day_9_1(std::string const& input);
	std::string day_9_2(std::string const& input);
	std::string day_10_1(std::string const& input);
	std::string day_10_2(std::string const& input);
	std::string day_11_1(std::string const& input);
	std::string day_11_2(std::string const& input);
	std::string day_12_1(std::string const& input);
	std::string day_12_2(std::string const& input);
	std::string day_13_1(std::string const& input);
	std::string day_13_2(std::string const& input);
	std::string day_14_1(std::string const& input);
	std::string day_14_2(std::string const& input);
	std::string day_15_1(std::string const& input);
	std::string day_15_2(std::string const& input);
	std::string day_16_1(std::string const& input);
	std::string day_16_2(std::string const& input);
	std::string day_17_1(std::string const& input);
	std::string day_17_2(std::string const& input);
	std::string day_18_1(std::string const& input);
	std::string day_18_2(std::string const& input);
	std::string day_19_1(std::string const& input);
	std::string day_19_2(std::string const& input);
	std::string day_20_1(std::string const& input);
	std::string day_20_2(std::string const& input);
	std::string day_21_1(std::string const& input);
	std::string day_21_2(std::string const& input);
	std::string day_22_1(std::string const& input);
	std::string day_22_2(std::string const& input);
	std::string day_23_1(std::string const& input);
	std::string day_23_2(std::string const& input);
	std::string day_24_1(std::string const& input);
	std::string day_24_2(std::string const& input);
	std::string day_25_1(std::string const& input);
	std::string day_25_2(std::string const& input);

	std::string get_test_input(day_t day, int variation);

	std::string run_day_with_default_input(day_t day, part_t part);
	std::string run_day_with_test_input(day_t day, part_t part, int variation);
	std::string run_day(day_t day, part_t part, std::string const& input);
} // namespace sb
