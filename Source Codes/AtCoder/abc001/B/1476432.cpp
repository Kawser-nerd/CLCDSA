#include <iostream>

int main()
{
	int m = 0, vv = 0;
	std::cin >> m;
	if (m >= 100 && 5000 >= m)
		vv = m / 100;
	else if (m >= 6000 && 30000 >= m)
		vv = m / 1000 + 50;
	else if (m >= 35000 && 70000 >= m)
		vv = (m / 1000 - 30) / 5 + 80;
	else if (m > 70000)vv = 89;
	if (vv < 10)
		std::cout << "0" << vv << std::endl;
	else
		std::cout << vv << std::endl;
    return 0;
}