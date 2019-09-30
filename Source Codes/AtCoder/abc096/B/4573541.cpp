#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(){
    std::vector<int> vec(3);
    for(int i = 0; i < 3; ++i){
        std::cin >> vec.at(i);
    }
    std::sort(vec.begin(), vec.end());

    int k;
    std::cin >> k;
    for(int i = 0; i < k; ++i){
        vec.at(2) *= 2;
    }

    std::cout << std::accumulate(vec.begin(), vec.end(), 0);

    return 0;
}