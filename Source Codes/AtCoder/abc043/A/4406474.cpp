#include <iostream>

int main(){
    int n;
    std::cin >> n;

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += i;
    }

    std::cout << ans << std::endl;
}