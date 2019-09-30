#include <iostream>
#include <string>
#include <unordered_map>
 
int main()
{
	const std::unordered_map<int, std::string> m{ {11, "Do"}, {9, "Re"}, {7, "Mi"}, {6, "Fa"}, {4, "So"}, {2, "La"}, {0, "Si"} };
	const std::string kb{"WWBWBWW"};
	std::string s;
	std::cin >> s;
	std::cout << m.at(s.find(kb)) << '\n';
}