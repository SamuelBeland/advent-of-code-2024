#include "days.hpp"

#include <adventlib/utilities.hpp>

#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

#define RUN_INDIVIDUAL_BENCHMARKS

//==============================================================================
TEST_CASE("day1")
{
	CHECK(sb::run_day_with_test_input(1, 1, 1) == "11");
	CHECK(sb::run_day_with_default_input(1, 1) == "2430334");

	CHECK(sb::run_day_with_test_input(1, 2, 1) == "31");
	CHECK(sb::run_day_with_default_input(1, 2) == "28786472");
}

////==============================================================================
// TEST_CASE("day2")
//{
//	// CHECK(sb::run_day_with_test_input(2, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(2, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(2, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(2, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day3")
//{
//	// CHECK(sb::run_day_with_test_input(3, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(3, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(3, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(3, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day4")
//{
//	// CHECK(sb::run_day_with_test_input(4, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(4, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(4, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(4, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day5")
//{
//	// CHECK(sb::run_day_with_test_input(5, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(5, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(5, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(5, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day6")
//{
//	// CHECK(sb::run_day_with_test_input(6, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(6, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(6, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(6, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day7")
//{
//	// CHECK(sb::run_day_with_test_input(7, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(7, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(7, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(7, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day8")
//{
//	// CHECK(sb::run_day_with_test_input(8, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(8, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(8, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(8, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day9")
//{
//	// CHECK(sb::run_day_with_test_input(9, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(9, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(9, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(9, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day10")
//{
//	// CHECK(sb::run_day_with_test_input(10, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(10, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(10, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(10, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day11")
//{
//	// CHECK(sb::run_day_with_test_input(11, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(11, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(11, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(11, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day12")
//{
//	// CHECK(sb::run_day_with_test_input(12, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(12, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(12, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(12, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day13")
//{
//	// CHECK(sb::run_day_with_test_input(13, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(13, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(13, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(13, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day14")
//{
//	// CHECK(sb::run_day_with_test_input(14, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(14, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(14, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(14, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day15")
//{
//	// CHECK(sb::run_day_with_test_input(15, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(15, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(15, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(15, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day16")
//{
//	// CHECK(sb::run_day_with_test_input(16, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(16, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(16, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(16, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day17")
//{
//	// CHECK(sb::run_day_with_test_input(17, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(17, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(17, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(17, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day18")
//{
//	// CHECK(sb::run_day_with_test_input(18, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(18, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(18, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(18, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day19")
//{
//	// CHECK(sb::run_day_with_test_input(19, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(19, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(19, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(19, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day20")
//{
//	// CHECK(sb::run_day_with_test_input(20, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(20, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(20, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(20, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day21")
//{
//	// CHECK(sb::run_day_with_test_input(21, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(21, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(21, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(21, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day22")
//{
//	// CHECK(sb::run_day_with_test_input(22, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(22, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(22, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(22, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day23")
//{
//	// CHECK(sb::run_day_with_test_input(23, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(23, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(23, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(23, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day24")
//{
//	// CHECK(sb::run_day_with_test_input(24, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(24, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(24, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(24, 2) == "");
// }
//
////==============================================================================
// TEST_CASE("day25")
//{
//	// CHECK(sb::run_day_with_test_input(25, 1, 1) == "");
//	// CHECK(sb::run_day_with_default_input(25, 1) == "");
//
//	// CHECK(sb::run_day_with_test_input(25, 2, 1) == "");
//	// CHECK(sb::run_day_with_default_input(25, 2) == "");
// }

//==============================================================================
#ifdef NDEBUG
TEST_CASE("Benchmarks")
{
#ifdef RUN_INDIVIDUAL_BENCHMARKS

	bool skip_individual_benchmarks = false;
	for (sb::day_t day = 1; day <= sb::NUM_DAYS; ++day)
	{
		for (sb::part_t part = 1; part <= sb::NUM_PARTS_PER_DAY; ++part)
		{
			auto name =
				std::string{ "day " } + std::to_string(day) + " part " + std::to_string(part);
			std::string last_result;
			BENCHMARK(name.c_str())
			{
				last_result = sb::run_day_with_default_input(day, part);
				return last_result;
			};

			if (last_result.empty())
			{
				// nothing implemented past this point: skip
				skip_individual_benchmarks = true;
				break;
			}
		}

		if (skip_individual_benchmarks)
		{
			break;
		}
	}

#endif

	BENCHMARK("ALL")
	{
		std::string result{};
		for (sb::day_t day = 1; day <= sb::NUM_DAYS; ++day)
		{
			for (sb::part_t part = 1; part <= sb::NUM_PARTS_PER_DAY; ++part)
			{
				auto const day_result = sb::run_day_with_default_input(day, part);

				if (day_result.empty())
				{
					// not implemented part this point: abort
					return result;
				}

				result.append(day_result);
			}
		}

		return result;
	};
}
#endif