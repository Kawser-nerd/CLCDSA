#include <iostream>

int main(void)
{
	std::string s;
	std::cin >> s;
	
	int answer = 0;
	if(s[0] == '1') ++answer;
	if(s[1] == '1') ++answer;
	if(s[2] == '1') ++answer;

	std::cout << answer << std::endl;

	return 0;
}