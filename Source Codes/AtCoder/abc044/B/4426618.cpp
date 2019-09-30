#include <iostream>
#include <string>
#include <algorithm>

int main(){
    std::string s;
    std::cin >> s;

    std::string ss = s;
    std::sort(ss.begin(), ss.end());
    ss.erase(std::unique(ss.begin(), ss.end()), ss.end());

    int counter;
    bool flg = false;
    for(int i = 0; i < ss.size(); ++i){
        counter = std::count(s.begin(), s.end(), ss.at(i));
        if(0 == counter%2){
            flg = true;
        }else{
            flg = false;
            break;
        }
    }
    
    if(flg){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
}