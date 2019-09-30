#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    long long n;
    std::cin >> n;

    std::vector<long long> vec{0, 0, 1};

    for(long long i = 3; i < n; ++i){
        vec.push_back((vec.at(i - 3) + vec.at(i - 2) + vec.at(i - 1)) % 10007);
    }

    std::cout << vec.at(n - 1) << std::endl;

    return 0;
}