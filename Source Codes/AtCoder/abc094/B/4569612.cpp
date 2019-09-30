#include <iostream>
#include <vector>

int main(){
    int n, m, x;
    std::cin >> n >> m >> x;

    std::vector<int> a(n + 1, 0);
    int i;
    for(int j = 0; j < m; ++j){
        std::cin >> i;
        a.at(i) = 1;
    }

    int left = std::count(a.begin(), a.begin() + x + 1, 1);
    int right = std::count(a.begin() + x, a.end(), 1);

    if(left < right){
        std::cout << left << std::endl;
    }else{
        std::cout << right << std::endl;
    }

    return 0;
}