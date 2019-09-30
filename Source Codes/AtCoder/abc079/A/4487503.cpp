#include <iostream>
#include <string>
#include <algorithm>

int main(){
    std::string str;
    std::cin >> str;

    if((str.at(0) == str.at(1) && str.at(1) == str.at(2)) || str.at(1) == str.at(2) && str.at(2) == str.at(3)){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
} ./Main.cpp:9:85: warning: '&&' within '||' [-Wlogical-op-parentheses]
    if((str.at(0) == str.at(1) && str.at(1) == str.at(2)) || str.at(1) == str.at(2) && str.at(2) == str.at(3)){
                                                          ~~ ~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~
./Main.cpp:9:85: note: place parentheses around the '&&' expression to silence this warning
    if((str.at(0) == str.at(1) && str.at(1) == str.at(2)) || str.at(1) == str.at(2) && str.at(2) == str.at(3)){
                                                                                    ^
                                                             (                                               )
1 warning generated.