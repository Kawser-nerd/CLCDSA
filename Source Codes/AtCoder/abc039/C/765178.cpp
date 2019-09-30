#include <iostream>
#include <string>
#include <vector>
 
int main()
{
	const std::vector<std::string> v{ "Si", "La#", "La", "So#", "So", "Fa#", "Fa", "Mi", "Re#", "Re", "Do#", "Do" };
	const std::string kb{"WWBWBWW"};
	std::string s;
	std::cin >> s;
	std::cout << v[s.find(kb)] << '\n';
}