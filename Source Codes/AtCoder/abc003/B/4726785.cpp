#include <iostream>

int main(){
    std::string s, t;
    std::cin >> s >> t;

    bool flg = true;
    int length = s.size();
    std::string ref = "atcoder@";
    for(int i = 0; i < length; ++i){
        if(s.at(i) != t.at(i)){
            if('@' == s.at(i) && std::string::npos != ref.find(t.at(i))){
                flg = true;
            }else if('@' == t.at(i) && std::string::npos != ref.find(s.at(i))){
                flg = true;
            }else{
                flg = false;
                break;
            }
        }
    }

    if(flg){
        std::cout << "You can win" << std::endl;
    }else{
        std::cout << "You will lose" << std::endl;
    }

    return 0;
}