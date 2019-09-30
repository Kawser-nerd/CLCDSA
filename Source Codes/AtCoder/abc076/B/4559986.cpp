#include <iostream>

int main(){
    int n, k;
    std::cin >> n >> k;

    int ans = 1;
    for(int i = 0; i < n; ++i){
        if(ans <= k){
            ans *= 2;
        }else{
            ans += k;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}