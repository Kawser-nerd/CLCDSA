#include <iostream>
#include <string>

int main()
{
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;

	std::string s = "Balanced";
	if( ( a + b ) > ( c + d ) ) {
		s = "Left";
	}
	if( ( a + b ) < ( c + d ) ) {
		s = "Right";
	}

	std::cout << s << std::endl;
	return 0;
}