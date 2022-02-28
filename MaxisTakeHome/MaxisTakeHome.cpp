#include <iostream>
#include <vector>
#include <map>
#include "Composer.h"
#include "DataReader.h"
#include "TimePeriod.h"

int main()
{
	std::vector<Composer*>* composers = DataReader::Read("input/dataset.txt"); // Get data on each composer
	std::map<unsigned int, unsigned int> composersPerYear; // associates a year with how many composers were alive during it

	for (auto& composer : *composers) // for each composer, add 1 to the alive total for each year 
	{
		for (unsigned int year = composer->birthYear; year <= composer->deathYear; ++year)
		{
			++composersPerYear[year];
		}
		std::free(composer); // free the memory as we no longer need this data
	}

	composers->~vector();

	TimePeriod greatestTimePeriod{};

	for (int year = composersPerYear.begin()->first; year <= 1993; ++year)
	{
		auto composersAlive = composersPerYear[year];

		std::cout << "Year: " << year << " Composers alive: " << composersAlive << std::endl;

		if (composersAlive > greatestTimePeriod.composersAlive) // we've found a new time period to track
		{
			greatestTimePeriod.startYear = year;
			greatestTimePeriod.composersAlive = composersAlive;
			greatestTimePeriod.endYear = year;
		}

		else if (composersAlive == greatestTimePeriod.composersAlive)
		{
			greatestTimePeriod.endYear = year;
		}
	}

	std::cout <<
		"\nThe most recent time period with the most composers alive is " <<
		greatestTimePeriod.startYear << "-" << greatestTimePeriod.endYear <<
		" with " << greatestTimePeriod.composersAlive <<
		" composers alive." << std::endl;

	return 0;
}
