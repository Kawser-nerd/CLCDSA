#include <iostream>
#include <map>
#include <cmath>

int main(){
    int n;
    float t, a;
    std::cin >> n >> t >> a;

    float diff;
    std::map<float, int> h{};
    for(int i = 1; i <= n; ++i){
        std::cin >> diff;
        diff = std::fabs(a - (t - diff * 0.006));
        h.insert(std::make_pair(diff, i));
    }
    
    std::cout << h.begin()->second << std::endl;

    return 0;
}