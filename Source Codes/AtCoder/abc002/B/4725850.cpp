#include <iostream>

int main(){
    std::string w;
    std::cin >> w;

    while(std::string::npos != w.find('a')){
        w.erase(w.begin() + w.find('a'));
    }

//    std::cout << w << std::endl;

    while(std::string::npos != w.find('i')){
        w.erase(w.begin() + w.find('i'));
    }

//    std::cout << w << std::endl;

    while(std::string::npos != w.find('u')){
        w.erase(w.begin() + w.find('u'));
    }

//    std::cout << w << std::endl;

    while(std::string::npos != w.find('e')){
        w.erase(w.begin() + w.find('e'));
    }

//    std::cout << w << std::endl;

    while(std::string::npos != w.find('o')){
        w.erase(w.begin() + w.find('o'));
    }

    std::cout << w << std::endl;

    return 0;

}