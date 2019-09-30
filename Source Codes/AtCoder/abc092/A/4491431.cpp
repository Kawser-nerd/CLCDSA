#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    
    std::vector<int> vec(4);
    vec.at(0) = a + c;
    vec.at(1) = a + d;
    vec.at(2) = b + c;
    vec.at(3) = b + d;

    std::cout << *std::min_element(vec.begin(), vec.end());

    return 0;
}