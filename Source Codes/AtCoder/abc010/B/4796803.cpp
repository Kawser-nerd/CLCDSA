#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> flowers(n);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        std::cin >> flowers.at(i);
        
        int count = 0;
        while(1 != flowers.at(i) % 2 || (1 != flowers.at(i) % 3 && 0 != flowers.at(i) %3)){
            ++count;
            --flowers.at(i);

//            std::cout << flowers.at(i) << std::endl;
        }

        ans += count;
    }

    std::cout << ans << std::endl;

    return 0;
}