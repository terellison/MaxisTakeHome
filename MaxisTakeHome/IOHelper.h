#include "Composer.h"
#include <vector>
#include <tuple>
#ifndef IOHELPER_H
#define IOHELPER_H

static class IOHelper
{
public:
	static std::vector<Composer>* GetComposerData(const char* fileName);
private:
	static std::tuple<int, int> getYearsAlive(std::string data);
	static std::string getName(std::string data);
};
#endif
