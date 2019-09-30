#include <iostream>

int main(){
    float w, h;
    std::cin >> w >> h;

    if(0.75 == h / w){
        std::cout << "4:3" << std::endl;
    }else{
        std::cout << "16:9" << std::endl;
    }

    return 0;
}