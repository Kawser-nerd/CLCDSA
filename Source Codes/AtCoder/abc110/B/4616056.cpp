#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, m, X, Y;
    std::cin >> n >> m >> X >> Y;

    std::vector<int> x(n);
    for(int i = 0; i < n; ++i){
        std::cin >> x.at(i);
    }

    std::vector<int> y(m);
    for(int i = 0; i < m; ++i){
        std::cin >> y.at(i);
    }

    bool flg = false;
    std::sort(x.begin(), x.end());
    int xMax = *max_element(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    int yMin = *min_element(y.begin(), y.end());
    if(xMax < yMin && xMax < Y && X < yMin){
        flg = true;
    }

    if(flg){
        std::cout << "No War" << std::endl;
    }else{
        std::cout << "War" << std::endl;
    }

    return 0;
}