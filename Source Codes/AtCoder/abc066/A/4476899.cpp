#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;

    std::vector<int> vec(3);
    vec.at(0) = a + b;
    vec.at(1) = b + c;
    vec.at(2) = c + a;

    std::cout << *std::min_element(vec.begin(), vec.end()) << std::endl;

    return 0;

}