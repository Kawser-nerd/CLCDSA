#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> time(n);
    for(int i = 0; i < n; ++i){
        std::cin >> time.at(i);
    }

    std::cout << *min_element(time.begin(), time.end()) << std::endl;

    return 0;
}