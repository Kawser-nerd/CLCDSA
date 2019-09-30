#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
    std::string r;
    std::string g;
    std::string b;

    std::cin >> r>>g>>b;
    std::string s= g+b;
    int num=std::stoi(s);
    if (num%4==0) {
        std::cout << "YES" << '\n';
    }
    else{
        std::cout << "NO" << '\n';
    }


    return 0;
}