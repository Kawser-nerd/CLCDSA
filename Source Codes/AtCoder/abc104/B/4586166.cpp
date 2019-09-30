#include <iostream>
#include <string>
#include <algorithm>

int main(){
    std::string s;
    std::cin >> s;

    bool flg = false;
    std::string strBuf;
    if('A' == *s.begin()){
        strBuf = s.substr(2, s.size() - 3);
        if(std::count(strBuf.begin(), strBuf.end(), 'C')){
            s.erase(s.begin() + s.find('A'));
            s.erase(s.begin() + s.find('C'));
            for(int i = 0; i < s.size(); ++i){
                if('a' <= s.at(i) && s.at(i) <= 'z'){
                    if(i == s.size() - 1){
                        flg = true;
                    }
                }else{
                    break;
                }
            } 
        }
    }
    
    if(flg){
        std::cout << "AC" << std::endl;
    }else{
        std::cout << "WA" << std::endl;
    }

    return 0;
}