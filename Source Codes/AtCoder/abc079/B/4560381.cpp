#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    std::vector<long long> l{2, 1};
    for(int i = 2; i <= n; ++i){
        l.push_back(l.at(i - 1) + l.at(i - 2));
    }

    std::cout << l.at(n) << std::endl;

    return 0;
}