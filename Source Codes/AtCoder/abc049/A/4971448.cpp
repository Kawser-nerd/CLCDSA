#include <iostream>

int main()
{
    char c;
    std::cin >> c;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ){
        std::cout << "vowel";
    }
    else{
        std::cout << "consonant";
    }
    return 0;
}