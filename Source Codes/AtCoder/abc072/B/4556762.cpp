#include <iostream>

int main(){
    std::string s;
    std::cin >> s;

    std::string ans = "";
    for(int i = 0; i < (s.size() + 1) / 2; ++i){
        ans += s.at(i * 2);
    }

    std::cout << ans << std::endl;

    return 0;
}