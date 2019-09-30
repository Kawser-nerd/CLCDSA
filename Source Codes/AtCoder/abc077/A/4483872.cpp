#include <iostream>
#include <vector>

int main(){
    std::vector<std::vector<char>> matrix(2, std::vector<char>(3));
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 3; ++j){
            std::cin >> matrix.at(i).at(j);
        }
    }

    std::vector<std::vector<int>> ans(2, std::vector<int>(3));
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 3; ++j){
            ans.at(i).at(j) = matrix.at(1 - i).at(2 - j);
        }
    }

    bool flg = false;
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 3; ++j){
            if(ans.at(i).at(j) == matrix.at(i).at(j)){
                flg = true;
            }else{
                flg = false;
                break;
            }
        }
    }

    if(flg){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }

    return 0;
}