#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

int main(){
    int n;
    std::cin >> n;

    int ans = 0;
    int val;
    for(int i = 0; i < n; ++i){
        std::cin >> val;
        while(0 == val % 2){
            val /= 2;
            ++ans;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}