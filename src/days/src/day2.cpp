#include "days.hpp"

#include <adventlib/Parser.hpp>
#include <adventlib/utilities.hpp>

#include <optional>

namespace
{
	constexpr std::size_t REPORT_PRE_ALLOCATE = 10;

	using level_t = std::int32_t;

	constexpr level_t MIN_LEVEL_INCREASE = 1;
	constexpr level_t MAX_LEVEL_INCREASE = 3;

	using Report = std::vector<level_t>;

	Report parse_report(std::string_view line)
	{
		Report result;
		result.reserve(REPORT_PRE_ALLOCATE);

		sb::for_each(line, ' ',
					 [&](std::string_view str) -> bool
					 {
						 result.push_back(sb::Parser<level_t>::parse(str));
						 return true;
					 });

		return result;
	}

	using Reports = std::vector<Report>;

	Reports parse_reports(std::string_view str)
	{
		return sb::transform(sb::split_lines(str), parse_report);
	}

	template<level_t MIN_DIFF, level_t MAX_DIFF>
	std::optional<std::size_t> get_invalid_increase_index(Report const& report)
	{
		std::optional<std::size_t> invalid_increase_index;
		level_t last = report.front();

		for (auto it = std::next(report.begin()); it != report.end(); ++it)
		{
			level_t const diff = *it - last;
			if (diff < MIN_DIFF || diff > MAX_DIFF)
			{
				return std::distance(report.begin(), it) - 1;
			}
			last = *it;
		}

		return std::nullopt;
	}

	bool is_safe_report(Report const& report)
	{
		return !get_invalid_increase_index<MIN_LEVEL_INCREASE, MAX_LEVEL_INCREASE>(report) ||
			   !get_invalid_increase_index<-MAX_LEVEL_INCREASE, -MIN_LEVEL_INCREASE>(report);
	}

	Report remove_from_report(Report const& report, std::size_t index)
	{
		Report reduced_report = report;
		reduced_report.erase(std::next(reduced_report.begin(), index));
		return reduced_report;
	}

	template<level_t MIN_DIFF, level_t MAX_DIFF>
	bool is_partially_safe_increasing_report(Report const& report)
	{
		if (auto invalid_index = get_invalid_increase_index<MIN_DIFF, MAX_DIFF>(report);
			invalid_index.has_value())
		{
			Report reduced_report = remove_from_report(report, *invalid_index);
			if (!get_invalid_increase_index<MIN_DIFF, MAX_DIFF>(reduced_report))
			{
				return true;
			}
			reduced_report = remove_from_report(report, *invalid_index + 1);
			if (!get_invalid_increase_index<MIN_DIFF, MAX_DIFF>(reduced_report))
			{
				return true;
			}
		}
		else
		{
			return true;
		}

		return false;
	}

	bool is_partially_safe_report(Report const& report)
	{
		return is_partially_safe_increasing_report<MIN_LEVEL_INCREASE, MAX_LEVEL_INCREASE>(
				   report) ||
			   is_partially_safe_increasing_report<-MAX_LEVEL_INCREASE, -MIN_LEVEL_INCREASE>(
				   report);
	}
} // namespace

std::string sb::day_2_1(std::string const& input)
{
	Reports const reports = parse_reports(input);
	auto const num_safe_reports = std::count_if(reports.begin(), reports.end(), is_safe_report);

	return sb::to_string(num_safe_reports);
}

std::string sb::day_2_2(std::string const& input)
{
	Reports const reports = parse_reports(input);
	auto const num_partially_safe_reports =
		std::count_if(reports.begin(), reports.end(), is_partially_safe_report);

	return sb::to_string(num_partially_safe_reports);
}
