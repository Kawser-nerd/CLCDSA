#include <iostream>
#include <vector>

int main(){
    int h, w;
    std::cin >> h >> w;

    std::string horizontalRef(w, '.');
    std::string buf;
    std::vector<std::string> matrix;
    for(int i = 0; i < h; ++i){
        std::cin >> buf;
        if(horizontalRef != buf){
            matrix.push_back(buf);
        }
    }

    int count;
    for(int i = matrix.at(0).size() - 1; i >= 0; --i){
        count = 0;
        for(int j = 0; j < matrix.size(); ++j){
            if('.' == matrix.at(j).at(i)){
                ++count;
            }
        }
        
        if(count == matrix.size()){
            for(int j = 0; j < matrix.size(); ++j){
                matrix.at(j).erase(matrix.at(j).begin() + i);
            }
        }
    }

    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix.at(i).size(); ++j){
            std::cout << matrix.at(i).at(j);
        }
        std::cout << std::endl;
    }

    return 0;
}