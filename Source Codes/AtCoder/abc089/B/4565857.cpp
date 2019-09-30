#include <iostream>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::string s;
    std::string arare{""};
    for(int i = 0; i < n; ++i){
        std::cin >> s;
        arare += s;
    }

    std::sort(arare.begin(), arare.end());
    arare.erase(std::unique(arare.begin(), arare.end()), arare.end());

    // for(int i = 0; i < arare.size(); ++i){
    //     std::cout << arare.at(i);
    // }
    // std::cout << std::endl;

    if(3 == arare.size()){
        std::cout << "Three" << std::endl;
    }else{
        std::cout << "Four" << std::endl;
    }

    return 0;
}