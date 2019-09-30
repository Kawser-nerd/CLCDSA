#include <iostream>
#include <algorithm>

int main(){
    std::string s, t;
    std::cin >> s >> t;

    bool flg =false;
    for(int i = 0; i < s.size(); ++i){
        s = s.substr(s.size() - 1, 1) + s.substr(0, s.size() - 1);
        if(s == t){
            flg = true;
            break;
        }
    }

    if(flg){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
}