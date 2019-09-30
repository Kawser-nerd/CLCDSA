#include <iostream>
#include <string>

int main() {
	std::string str;
	int ans = 0;
	std::cin >> str;

	if (str[0] == '1') ans++;
	if (str[1] == '1') ans++;
	if (str[2] == '1') ans++;
	
	std::cout << ans << std::endl;
	return 0;
}