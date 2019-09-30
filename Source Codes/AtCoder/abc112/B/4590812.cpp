#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, T;
    std::cin >> n >> T;

    std::vector<int> routes;
    int c, t;
    for(int i = 0; i < n; ++i){
        std::cin >> c >> t;
        if(t <= T){
            routes.push_back(c);
        }
    }

    std::sort(routes.begin(), routes.end());
    if(0 == routes.size()){
        std::cout << "TLE" << std::endl;
    }else{
        std::cout << *routes.begin() << std::endl;
    }

    return 0;
}