#include <iostream>
#include <string>
#include <vector>

int main(){
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(1, std::string(w + 2, '_'));
    std::string strBuf;
    for(int i = 0; i < h; ++i){
        std::cin >> strBuf;
        s.push_back("_" + strBuf + "_");
    }
    s.push_back(std::string(w + 2, '_'));

    char counter;
    for(int i = 1; i < h + 1; ++i){
        for(int j = 1; j < w + 1; ++j){
            counter = '0';
            if('.' == s.at(i).at(j)){
                for(int k = -1; k < 2; ++k){
                    for(int l = -1; l < 2; ++l){
                        if('#' == s.at(i + k).at(j + l)){
                            ++counter;
                        }
                    }
                }
                s.at(i).at(j) = counter;
            }
        }
    }
    
    for(int i = 1; i < h + 1; ++i){
        for(int j = 1; j < w + 1; ++j){
            std::cout << s.at(i).at(j);
        }
        std::cout << std::endl;
    }

    return 0;
}