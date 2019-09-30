#include <iostream>

int main(){
    int s, e;
    int ans = 0;
    for(int i = 0; i < 3; ++i){
        std::cin >> s >> e;
        ans += s * e / 10;
    }

    std::cout << ans << std::endl;

    return 0;
}