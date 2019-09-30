#include <iostream>
#include <algorithm>

int main(){
    int a, b;
    std::cin >> a >> b;

    std::string s;
    std::cin >> s;

    bool flg = false;
    for(int i = 0; i < s.size(); ++i){
        // std::cout << "s.at(" << i << "): " << s.at(i) << std::endl;
        if(std::string::npos == s.find('-')){
            break;
        }else if('-' == s.at(i)){
            if(a != i){
                break;
            }
        }else if(s.at(i) < '0' || '9' < s.at(i)){
            break;
        }else if(s.size() - 1 == i){
            flg = true;
        }
    }

    if(flg){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
}