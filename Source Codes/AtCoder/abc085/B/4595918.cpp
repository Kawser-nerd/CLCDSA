#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for(int i = 0; i < n; ++i){
        std::cin >> vec.at(i);
    }

    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    
    std::cout << vec.size() << std::endl;

    return 0;
}