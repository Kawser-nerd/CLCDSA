#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    std::string s;
    std::cin >> s;

    std::transform(s.begin(), s.end(), s.begin(), tolower);
    s.at(0) -= 32;

    std::cout << s << std::endl;

    return 0;
}