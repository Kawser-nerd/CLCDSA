#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, l;
    std::cin >> n >> l;

    std::vector<std::string> str(n, "");
    for(int i = 0; i < n; ++i){
        std::cin >> str.at(i);
    }

    std::sort(str.begin(), str.end());

    std::string ans = "";
    for(int i = 0; i < n; ++i){
        ans += str.at(i);
    }
    
    std::cout << ans << std::endl;
}