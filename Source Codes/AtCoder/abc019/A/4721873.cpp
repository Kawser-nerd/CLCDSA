#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> ages(3);
    for(int i = 0; i < 3; ++i){
        std::cin >> ages.at(i);
    }

    std::sort(ages.begin(), ages.end());

    std::cout << ages.at(1) << std::endl;

    return 0;
}