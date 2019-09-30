#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    int n;
    long x;
    std::cin >> n >> x;

    long buf;
    unsigned long mask = 1;
    long ans = 0;
    for(int i = 0; i < n; ++i){
        std::cin >> buf;
        if(mask & x){
            ans += buf;
        }
        mask = mask << 1;
    }
    
    std::cout << ans << std::endl;

    return 0;
}