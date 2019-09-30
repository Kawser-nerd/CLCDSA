#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <sstream>

int main(){
    int n;
    std::cin >> n;

    std::stringstream hour;
    hour << std::setw(2) << std::setfill('0') << n / 3600;
    std::stringstream min;
    min << std::setw(2) << std::setfill('0') << (n % 3600) / 60;
    std::stringstream sec;
    sec << std::setw(2) << std::setfill('0') << (n % 3600) % 60;

    std::cout << hour.str() << ":" << min.str() << ":" << sec.str() << std::endl;

    return 0;
}