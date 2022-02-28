#include "DataReader.h"
#include <fstream>
#include <iostream>
std::vector<Composer*>* DataReader::Read(const char* fileName)
{
	std::vector<Composer*>* val = new std::vector<Composer*>();
	std::ifstream inputFile(fileName);
	
	if (inputFile.is_open())
	{
		std::string line;
		while (std::getline(inputFile, line))
		{
			Composer* newComposer = new Composer();
			std::string composerLifetime = line.substr(line.find('(')+1, line.find(')')-1);
			auto yearsAlive = getYearsAlive(composerLifetime);
			newComposer->birthYear = std::get<0>(yearsAlive);
			newComposer->deathYear = std::get<1>(yearsAlive);
			val->push_back(std::move(newComposer));
		}
		inputFile.close();
	}

	return val;
}

std::tuple<int,int> DataReader::getYearsAlive(std::string data)
{
	const unsigned int ASSUMED_DEATH_YEAR = 1993;
	std::string birth = data.substr(0, 4), death = data.substr(5, 8);
	int birthYear = stoi(birth);
	int deathYear = death == "    " ? ASSUMED_DEATH_YEAR : stoi(death);
	return std::make_tuple(birthYear, deathYear);
}