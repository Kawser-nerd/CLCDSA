#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    int n, m;
    std::cin >> n >> m;

    int k, index;
    std::vector<std::string> likes(m, std::string(n, '.'));
    for(int i = 0; i < n; ++i){
        std::cin >> k;
        for(int j = 0; j < k; ++j){
            std::cin >> index;
            likes.at(index - 1).at(i) = '#';
        }
    }

    std::cout << std::count(likes.begin(), likes.end(), std::string(n, '#')) << std::endl;

    return 0;
}