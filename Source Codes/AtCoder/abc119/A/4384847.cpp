#include <iostream>

int main (void)
{
	// variables for main process
	char buf;
	int  year, month, day;


	// STEP.01
	// read out the target date
	std::cin >> year >> buf >> month >> buf >> day;

	// STEP.02
	// judge the month
	// output the result
	if( month <= 4 ) { std::cout << "Heisei" << std::endl; }
	else             { std::cout << "TBD"    << std::endl; }

	// STEP.END
	return 0;
}