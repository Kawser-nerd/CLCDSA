#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    long long ans;
    long long l, r;
    for(int i = 0; i < n; ++i){
        std::cin >> l >> r;
        ans += r - l + 1;
    }    

    std::cout << ans << std::endl;

    return 0;
}