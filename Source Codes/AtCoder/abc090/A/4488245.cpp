#include <iostream>
#include <vector>

int main(){
    std::vector<char> vec(9);
    for(int i = 0; i < 9; ++i){
        std::cin >> vec.at(i);
    }

    std::cout << vec.at(0) << vec.at(4) << vec.at(8) << std::endl;

    return 0;
}