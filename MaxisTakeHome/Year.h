#include <vector>
#include <string>
#ifndef YEAR_H
#define YEAR_H
struct Year
{
	int currentYear;
	std::vector<std::string> composersAlive;
	Year* nextYear = NULL;
};
#endif // !YEAR_H