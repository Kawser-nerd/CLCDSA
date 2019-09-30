#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a.at(i);
    }

    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());

    long ans = 0;
    for(int i = 0; i < a.size() - 1; ++i){
            ans += a.at(i + 1) - a.at(i);
    }

    std::cout << ans << std::endl;

    return 0;
}