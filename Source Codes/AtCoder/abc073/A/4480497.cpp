#include <iostream>
#include <string>

int main(){
    std::string n;
    std::cin >> n;

    if(std::string::npos == n.find('9')){
        std::cout << "No" << std::endl;
    }else{
        std::cout << "Yes" << std::endl;
    }

    return 0;
}