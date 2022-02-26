#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "Composer.h"
#include "IOHelper.h"
#include "TimePeriod.h"

int main()
{
	std::vector<Composer>* composerList = IOHelper::GetComposerData("input/dataset.txt");
	std::map<int, int> years;

	for (auto& composer : *composerList)
	{
		int i = composer.birthYear;
		while (i <= composer.deathYear)
		{
			++years[i];
			++i;
		}
	}
	int maxAlive = 0, mostRecentYear = 0;
	TimePeriod* greatestTimePeriod = new TimePeriod();
	for (auto &year : years)
	{
		if (year.first > greatestTimePeriod->endYear && year.second > greatestTimePeriod->composersAlive) // we've found a new time period to track
		{
			greatestTimePeriod->startYear = year.first;
			greatestTimePeriod->composersAlive = year.second;
			greatestTimePeriod->endYear = year.first;
		}

		else if (year.first > greatestTimePeriod->startYear && year.second == greatestTimePeriod->composersAlive)
		{
			++greatestTimePeriod->endYear;
		}
	}

	std::cout <<
		"\nThe most recent time period with the most composers alive is " <<
		greatestTimePeriod->startYear << " - " << greatestTimePeriod->endYear << " with " << greatestTimePeriod->composersAlive << " composers alive." << std::endl;
}
