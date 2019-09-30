#include <iostream>

int main(){
    std::string a, s, c;
    std::cin >> a >> s >> c;

    std::string ans = "";
    ans += a.at(0);
    ans += s.at(0);
    ans += c.at(0);

    std::cout << ans << std::endl;
}