#include "DataReader.h"
#include <fstream>
#include <iostream>
std::vector<Composer*>* DataReader::Read(const char* fileName, const unsigned int ASSUMED_DEATH_YEAR)
{
	std::vector<Composer*>* val = new std::vector<Composer*>();
	std::ifstream inputFile(fileName);
	
	if (inputFile.is_open())
	{
		std::string line;
		while (std::getline(inputFile, line))
		{
			auto newComposer = new Composer();
			std::string composerLifetime = line.substr(line.find('(')+1, line.find(')')-1); // getting just the years the composer was alive
			auto yearsAlive = getYearsAlive(composerLifetime, ASSUMED_DEATH_YEAR);
			newComposer->birthYear = std::get<0>(yearsAlive);
			newComposer->deathYear = std::get<1>(yearsAlive);
			val->push_back(std::move(newComposer));
		}
		inputFile.close();
	}

	return val;
}

std::tuple<int,int> DataReader::getYearsAlive(std::string data, const unsigned int ASSUMED_DEATH_YEAR)
{
	std::string birth = data.substr(0, 4), death = data.substr(5, 8); // get the birth and death years using known offsets
	auto birthYear = stoi(birth);
	auto deathYear = death == "    " ? ASSUMED_DEATH_YEAR : stoi(death); // if the death year is blank then used the assumed death year
	return std::make_tuple(birthYear, deathYear);
}