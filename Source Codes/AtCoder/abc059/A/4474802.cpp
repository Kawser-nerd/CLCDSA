#include <iostream>
#include <string>

int main(){
    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    std::string buf;
    std::cout << (char)(s1.at(0) - 32) << (char)(s2.at(0) - 32) << (char)(s3.at(0) - 32) << std::endl;

    return 0;
}