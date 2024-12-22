#include "days.hpp"

#include <adventlib/Parser.hpp>
#include <adventlib/utilities.hpp>

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

	template<level_t MIN_DIFF, level_t MAX_DIFF> bool is_valid_increase(Report const& report)
	{
		level_t last = report.front();

		for (auto it = std::next(report.begin()); it != report.end(); ++it)
		{
			level_t const diff = *it - last;
			if (diff < MIN_DIFF || diff > MAX_DIFF)
			{
				return false;
			}
			last = *it;
		}

		return true;
	}

	bool is_safe_report(Report const& report)
	{
		if (is_valid_increase<MIN_LEVEL_INCREASE, MAX_LEVEL_INCREASE>(report))
		{
			return true;
		}
		if (is_valid_increase<-MAX_LEVEL_INCREASE, -MIN_LEVEL_INCREASE>(report))
		{
			return true;
		}

		return false;
	}
} // namespace

std::string sb::day_2_1(std::string const& input)
{
	Reports const reports = parse_reports(input);
	auto const num_safe_reports = std::count_if(reports.begin(), reports.end(), is_safe_report);

	return sb::to_string(num_safe_reports);
}

std::string sb::day_2_2(std::string const& /*input*/)
{
	return "";
}
