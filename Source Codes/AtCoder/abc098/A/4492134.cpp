#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int a, b;
    std::cin >> a >> b;

    std::vector<int> vec(3);
    vec.at(0) = a + b;
    vec.at(1) = a - b;
    vec.at(2) = a * b;

    std::cout << *std::max_element(vec.begin(), vec.end()) << std::endl;

    return 0;
}