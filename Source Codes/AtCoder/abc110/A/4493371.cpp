#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> vec(3);
    std::cin >> vec.at(0) >> vec.at(1) >> vec.at(2);

    std::sort(vec.begin(), vec.end());
    std::cout << vec.at(2) * 10 + vec.at(0) + vec.at(1) << std::endl;

    return 0;
}