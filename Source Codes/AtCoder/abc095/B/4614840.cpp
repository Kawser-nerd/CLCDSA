#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, x;
    std::cin >> n >> x;

    std::vector<int> m(n);
    for(int i = 0; i < n; ++i){
        std::cin >> m.at(i);
        x -= m.at(i);
    }

    std::sort(m.begin(), m.end());
    while(x >= m.at(0)){
        ++n;
        x -= m.at(0);
    }

    std::cout << n << std::endl;

    return 0;
}