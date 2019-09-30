#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    int a, b, c, k, s, t;
    std::cin >> a >> b >> c >> k >> s >> t;

    int ans = a * s + b * t;
    if(s + t >= k){
        ans -= (s + t) * c;
    }

    std::cout << ans << std::endl;

    return 0;
}