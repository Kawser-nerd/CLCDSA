#include <iostream>
#include <vector>

int main(){
    int w, h ,n;
    std::cin >> w >> h >> n;
    std::vector<int> a1{0};
    std::vector<int> a2{w};
    std::vector<int> a3{0};
    std::vector<int> a4{h};
    
    int x, y, a;
    for(int i = 0; i < n; ++i){
        std::cin >> x >> y >> a;
        switch(a){
            case 1:
                a1.push_back(x);
                break;
            case 2:
                a2.push_back(x);
                break;
            case 3:
                a3.push_back(y);
                break;
            case 4:
                a4.push_back(y);
                break;
        }
    }

    int xVariance = *std::min_element(a2.begin(), a2.end()) - *std::max_element(a1.begin(), a1.end());
    int yVariance = *std::min_element(a4.begin(), a4.end()) - *std::max_element(a3.begin(), a3.end());
    
    if(xVariance < 0 || yVariance < 0){
        std::cout << 0 << std::endl;
    }else{
        std::cout << xVariance * yVariance << std::endl;
    }

    return 0;
}