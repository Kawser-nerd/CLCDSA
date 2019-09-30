#include <iostream>
#include <sstream>

int main(){
    std::string str;
    std::cin >> str;

    for(int i = 0; i < 3; ++i){
        if('1' == str.at(i)){
            str.at(i) = '9';
        }else{
            str.at(i) = '1';
        }
    }

    std::stringstream ss;
    ss << str;

    int ans;
    ss >> ans;

    std::cout << ans << std::endl;

    return 0;
}