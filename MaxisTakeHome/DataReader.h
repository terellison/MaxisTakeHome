#include "Composer.h"
#include <vector>
#include <tuple>
#include <string>
#ifndef DATAREADER_H
#define DATAREADER_H

class DataReader
{
public:
	static std::vector<Composer*>* Read(const char* fileName, const unsigned int ASSUMED_DEATH_YEAR);
private:
	static std::tuple<int, int> getYearsAlive(std::string data, const unsigned int ASSUMED_DEATH_YEAR);
};
#endif
