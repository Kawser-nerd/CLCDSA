#include <iostream>
#include <string>

int main(){
    std::string a, b, c;
    std::cin >> a >> b >> c;

    if(*(a.end() - 1) == *b.begin() && *(b.end() - 1) == *c.begin()){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
}