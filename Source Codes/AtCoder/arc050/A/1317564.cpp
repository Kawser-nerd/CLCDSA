#include <iostream>
char C, c;
int main(void){
    std::cin >> C >> c;
    std::cout << ( ((int)(C-'A') == (int)(c-'a')) ? "Yes" : "No") << std::endl;
}