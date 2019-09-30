#include <iostream>
#include <string>

int main(){
    std::string s;
    std::cin >> s;
    
    std::string::iterator itr = s.begin();
    while(!s.empty() && s.end() != itr){
        if('B' == *itr){
            if(s.begin() == itr){
                s.erase(itr);
            }else{
                itr = s.erase(itr - 1, itr + 1);
                //--itr;
            }
        }else{
            ++itr;
        }
    } 
    std::cout << s << std::endl;
}