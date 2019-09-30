#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> vec(3);
    for(int i = 0; i < 3; ++i){
        std::cin >> vec.at(i);
    }

    for(int i = 0; i < 3; ++i){
        if(2 != std::count(vec.begin(), vec.end(), vec.at(i))){
            std::cout << vec.at(i) << std::endl;
            break;
        }
    }

    return 0;
}