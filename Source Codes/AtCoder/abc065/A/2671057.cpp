#include <iostream>
#include <string>

int main()
{
	int x, a, b;
	std::cin >> x >> a >> b;

	std::string ans = "";
	int d = b - a;
	if( d <= 0 ) {
		ans = "delicious";
	}
	else if( 0 < d and d <= x ) {
		ans = "safe";
	}
	else {
		ans = "dangerous";
	}
	
	std::cout << ans << std::endl;
	return 0;
}