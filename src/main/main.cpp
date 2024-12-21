#include "days.hpp"

#include <iostream>

//==============================================================================
// TODO : add some cleaner CLI options.
int main(int /*argc*/, char const** /*argv*/)
{
	for (sb::day_t day = 1; day < sb::NUM_DAYS; ++day)
	{
		for (sb::part_t part = 1; part <= sb::NUM_PARTS_PER_DAY; ++part)
		{
			auto const result = sb::run_day_with_default_input(day, part);

			if (result.empty())
			{
				// not implemented past this point: abort
				return false;
			}

			std::cout << "day " << day << " part " << part << ":\n" << result << "\n\n";
		}
	}

	return 0;
}