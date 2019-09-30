#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    std::string str;
    std::cin >> str;

    bool flg = false;
    int center = (str.size() + 1) / 2;
    int clip;
    for(int i = 1; i <= center; ++i){
        clip = (str.size() + 1) / 2 - i;
//       std::cout << str.substr(0, clip) << std::endl;
//       std::cout << str.substr(clip, clip) << std::endl;
        if(str.substr(0, clip) == str.substr(clip, clip)){
            flg = true;
            break;
        }
    }

    std::cout << clip * 2 << std::endl;

    return 0;
}