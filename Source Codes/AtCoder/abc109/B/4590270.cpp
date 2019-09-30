#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::vector<std::string> w(n);
    bool flg = false;
    std::cin >> w.at(0);
    for(int i = 1; i < n; ++i){
        std::cin >> w.at(i);
        if(*(w.at(i - 1).end() - 1) != *w.at(i).begin()){
            break;
        }else if(1 != std::count(w.begin(), w.end(), w.at(i))){
            break;
        }else if(i == n -1){
            flg = true;
        }
    }

    if(flg){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
}