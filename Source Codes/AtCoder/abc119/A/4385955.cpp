// AtCoder Beginner Contest 119 A
// [URL]      https://atcoder.jp/contests/abc119/tasks/abc119_a
// [compiler] C++14 (GCC 5.4.1)
// [reference]
// <1> https://cpprefjp.github.io/reference/string/basic_string/substr.html
// 
#include <iostream>
#include <string>

int main (void)
{
	// variables for main process
	std::string date;


	// STEP.01
	// read out the target date as a string
	std::cin >> date;

	// STEP.02
	// 1. judge the read date
	if( date <= "2019/04/30" )
	{ std::cout << "Heisei" << std::endl; }
	else
	{ std::cout << "TBD" << std::endl; }

	// STEP.END
	return 0;
}