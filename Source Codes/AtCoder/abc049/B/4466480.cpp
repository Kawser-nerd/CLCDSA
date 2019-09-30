#include <iostream>
#include <map>
#include <string>

int main(){
    int h, w;
    std::cin >> h >> w;

    int limit = h*w;
    char i, j;    
    std::string keyBuf;
    char valBuf;
    std::map<std::string, char> image;
    for(int i = 1; i <= h; ++i){
        for(int j = 1; j <= w; ++j){
            keyBuf = std::to_string(i) + "," + std::to_string(j);
            std::cin >> valBuf;
            image[keyBuf] = valBuf;
        }
    }

    for(int i = 1; i <= 2*h; ++i){
        for(int j = 1; j <= w; ++j){
            keyBuf = std::to_string((i + 1)/2) + "," + std::to_string(j);
        std::cout << image[keyBuf];
        }
        std::cout << std::endl;
    }

    return 0;
}