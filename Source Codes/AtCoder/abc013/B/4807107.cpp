#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    int a, b;
    std::cin >> a >> b;
    
    int first = abs(a - b);
    int second = 10 - first;

    std::cout << std::min(first, second) << std::endl;

    return 0;
}