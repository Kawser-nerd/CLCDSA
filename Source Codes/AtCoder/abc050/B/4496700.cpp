#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> t(n);
    for(int i = 0; i < n; ++i){
        std::cin >> t.at(i);
    }

    int m;
    std::cin >> m;

    std::vector<std::vector<int>> med(m, std::vector<int>(3));
    int p, x;
    for(int i = 0; i < m; ++i){
        std::cin >> p >> x;
        med.at(i).at(0) = p - 1;
        med.at(i).at(1) = x;
    }

    std::vector<int> tBuf(n);
    int ans;
    for(int i = 0; i < m; ++i){
        tBuf = t;
        ans = 0;
        tBuf.at(med.at(i).at(0)) = med.at(i).at(1);
        for(const auto& e : tBuf){
             ans += e;
        }

        std::cout << ans << std::endl;
    }

    return 0;
}