#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    std::vector<long> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a.at(i);
    }

    int val;
    std::vector<long> diff;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            val = abs(a.at(i) - a.at(j));
            diff.push_back(val);
        }
    }

    std::cout << *max_element(diff.begin(), diff.end()) << std::endl;

    return 0;
}