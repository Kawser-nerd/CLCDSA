#include <iostream>
#include <vector>

int main(){
    int n, k;
    std::cin >> n >> k;

    std::vector<int> sticks(n);
    for(int i = 0; i < n; ++i){
        std::cin >> sticks.at(i);
    }

    std::sort(sticks.begin(), sticks.end());
    std::reverse(sticks.begin(), sticks.end());

    int ans = 0;
    for(int i = 0; i < k; ++i){
        ans += sticks.at(i);
    }

    std::cout << ans << std::endl;

    return 0;
}