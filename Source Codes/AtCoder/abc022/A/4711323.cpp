#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    int n, s, t, w;
    std::cin >> n >> s >> t >> w;

    int a;
    int count = 0;
    if(s <= w && w <= t){
        ++count;
    }
    for(int i = 2; i <= n; ++i){
        std::cin >> a;
        w += a;
        if(s <= w && w <= t){
            ++count;
        }
    }

    std::cout << count << std::endl;

    return 0;
}