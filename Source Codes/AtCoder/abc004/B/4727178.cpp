#include <iostream>
#include <vector>
#include <utility>

int main(){
    std::vector<std::vector<char>> matrix(4, std::vector<char>(4));
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            std::cin >> matrix.at(i).at(j);
//            std::cout << matrix.at(i) << std::endl;
        }
    }

    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 4; ++j){
            std::swap(matrix.at(i).at(j), matrix.at(3 - i).at(3 - j));
        }
    }

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            std::cout << matrix.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
    

    return 0;
}