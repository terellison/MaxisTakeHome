#include <iostream>
#include <vector>
#include <algorithm>
#include "Year.h"
#include "Composer.h"
#include "IOHelper.h"

int main()
{
	std::vector<Composer>* composerList =  IOHelper::GetComposerData("input/dataset.txt");
	std::vector<Year> timeline;

	for (auto composer : composerList)
	{
		std::cout <<
			"Composer name: " << composer.name << std::endl <<
			"Birth year: " << composer.birthYear << std::endl <<
			"Death year: " << composer.deathYear << "\n\n";
	}
}
