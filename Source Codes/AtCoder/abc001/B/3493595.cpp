#include <iostream>
#include <iomanip>

int main()
{
    int m, vv;
    std::cin >> m;

    float km = static_cast<float>(m) / 1000;

    if(km < 0.1)
	vv = 0;
    else if(0.1 <= km and km <= 5)
	vv = km * 10;
    else if(6 <= km and km <= 30)
	vv = km + 50;
    else if (35 <= km and km <= 70)
	vv = ((km - 30) / 5) + 80;
    else if(70 < km)
	vv = 89;
    
    std::cout << std::setw(2) << std::setfill('0') << vv << std::endl;
}