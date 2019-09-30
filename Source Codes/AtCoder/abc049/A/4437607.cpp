#include <iostream>

int main(){
    char c;
    std::cin >> c;

    bool flg = false;
    switch(c){
        case 'a':
        case 'i':
        case 'u':
        case 'e':
        case 'o':
            flg = true;
            break;
        default:
            break;
    }

    if(flg){
        std::cout << "vowel" << std::endl;
    }else{
        std::cout << "consonant" << std::endl;
    }

    return 0;
}