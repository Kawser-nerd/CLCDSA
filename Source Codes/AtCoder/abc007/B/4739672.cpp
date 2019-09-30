#include <iostream>

int main(){
    std::string a;
    std::cin >> a;

    bool flg = false;
    if(1 == a.size() && 'a' == a.at(0)){
        flg = true;
    }

    if(flg){
        std::cout << -1 << std::endl;    
    }else{
        if(1 == a.size()){
            a.at(0) = a.at(0) - 1;
        }else{
            a.erase(a.end() - 1);
        }
        std::cout << a << std::endl;
    }

    return 0;
}