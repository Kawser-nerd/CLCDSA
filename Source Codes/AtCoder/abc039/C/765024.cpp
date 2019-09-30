#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
	const std::unordered_map<int, std::string> m{ {0, "Do"}, {2, "Re"}, {4, "Mi"}, {5, "Fa"}, {7, "So"}, {9, "La"}, {11, "Si"} };
	const std::string kb{"WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWB"};
	std::string s;
	std::cin >> s;
	std::cout << m.at(kb.find(s)) << '\n';
}