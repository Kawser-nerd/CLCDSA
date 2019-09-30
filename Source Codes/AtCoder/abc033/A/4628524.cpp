#include <iostream>
#include <algorithm>

int main(){
    std::string n;
    std::cin >> n;

    n.erase(std::unique(n.begin(), n.end()), n.end());

    if(1 == n.size()){
        std::cout << "SAME" << std::endl;
    }else{
        std::cout << "DIFFERENT" << std::endl;
    }

    return 0;
}