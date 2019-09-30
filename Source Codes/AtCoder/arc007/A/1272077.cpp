#include <iostream>
char X = 0;
std::string s;
int main(void){
    std::cin >> X;
    std::cin >> s;
    for(std::string::iterator c = s.begin(); c != s.end(); c++){
        if(*c != X){
            std::cout << *c;
        }
    }
    std::cout << std::endl;
}