#include "Composer.h"
#include <vector>
#include <tuple>
#ifndef DATAREADER_H
#define DATAREADER_H

class DataReader
{
public:
	static std::vector<Composer*>* Read(const char* fileName);
private:
	static std::tuple<int, int> getYearsAlive(std::string data);
	static std::string getName(std::string data);
};
#endif
