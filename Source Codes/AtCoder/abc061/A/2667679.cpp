#include <iostream>
#include <string>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	std::string ans = "";
	if( a <= c and c <= b ) {
		ans = "Yes";
	}
	else {
		ans = "No";
	}

	std::cout << ans << std::endl;
	return 0;
}