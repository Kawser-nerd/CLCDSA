#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    int x;
    std::cin >> x;

    int ans = 0;
    while(0 != x){
        ans += x % 10;
        x /= 10;
    }

    std::cout << ans << std::endl;

    return 0;
}