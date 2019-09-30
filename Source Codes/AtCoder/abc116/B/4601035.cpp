#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<long> a(1);
    std::cin >> a.at(0);

    bool flg = false;
    int val;
    while(!flg){
        val = a.at(a.size() - 1);

//        std::cout << "val: " << val << std::endl;

        if(0 == val % 2){
            val = val / 2;
        }else{
            val = 3 * val + 1;
        }

        a.push_back(val);

        if(2 == std::count(a.begin(), a.end(), val)){
            flg = true;
            break;
        }
    }

    std::cout << a.size() << std::endl;

    return 0;
}