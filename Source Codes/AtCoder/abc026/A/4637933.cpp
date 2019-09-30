#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int a;
    std::cin >> a;

    std::vector<int> vec(a);
    for(int i = 1; i <= a; ++i){
        vec.at(i - 1) = i * (a - i);
    }

    std::cout << *max_element(vec.begin(), vec.end()) << std::endl;

    return 0;
}