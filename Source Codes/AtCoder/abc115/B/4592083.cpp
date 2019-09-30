#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for(int i = 0; i < n; ++i){
        std::cin >> vec.at(i);
    }

    std::sort(vec.begin(), vec.end());
    *(vec.end() - 1) = *(vec.end() - 1) / 2;

    std::cout << std::accumulate(vec.begin(), vec.end(), 0) << std::endl;

    return 0;
}