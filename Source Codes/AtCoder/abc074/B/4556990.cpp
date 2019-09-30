#include <iostream>
#include <vector>

int main(){
    int n, k;
    std::cin >> n >> k;

    int x;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        std::cin >> x;
        if(k - x > x){
            ans += 2 * x;
        }else{
            ans += 2 * (k - x);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}