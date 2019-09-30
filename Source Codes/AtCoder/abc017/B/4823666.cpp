#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    std::string s;
    std::cin >> s;

    int i = 0;
    bool flg = true;
    while(s.size() != i){
        if('o' == s.at(i) || 'k' == s.at(i) || 'u' == s.at(i)){
            i += 1;
        }else if("ch" == s.substr(i, 2)){
            i += 2;
        }else{
            flg = false;
            break;
        }
    }

    if(flg){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}