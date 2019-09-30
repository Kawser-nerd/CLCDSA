#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    int val;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        std::cin >> val;
        ans += (val - 1);
    }

    std::cout << ans << std::endl;

    return 0;
}