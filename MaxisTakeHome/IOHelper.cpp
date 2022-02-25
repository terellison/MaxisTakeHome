#include "IOHelper.h"
#include <fstream>
#include <iostream>
std::vector<Composer>* IOHelper::GetComposerData(const char* fileName)
{
	std::vector<Composer>* val = new std::vector<Composer>();
	std::ifstream inputFile(fileName);
	
	if (inputFile.is_open())
	{
		std::string line;
		while (std::getline(inputFile, line))
		{
			Composer newComposer;
			std::string composerLifetime = line.substr(line.find('(')+1, line.find(')')-1);
			auto yearsAlive = getYearsAlive(composerLifetime);
			newComposer.birthYear = std::get<0>(yearsAlive);
			newComposer.deathYear = std::get<1>(yearsAlive);
			newComposer.name = getName(line);
			val->push_back(newComposer);
		}
		inputFile.close();
	}

	return val;
}

std::tuple<int,int> IOHelper::getYearsAlive(std::string data)
{
	std::string birth = data.substr(0, 4), death = data.substr(5, 8);
	int birthYear = stoi(birth);
	int deathYear = death == "    " ? 1997 : stoi(death);
	return std::make_tuple(birthYear, deathYear);
}

std::string IOHelper::getName(std::string data)
{
	return data.substr(data.find(')')+2, data.find('\0'));
}
