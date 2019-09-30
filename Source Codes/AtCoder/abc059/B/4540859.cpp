#include <iostream>

int main(){
    std::string a, b;
    std::cin >> a >> b;

    char flg;
    if(a.size() == b.size()){
        for(int i = 0; i < a.size(); ++i){
            if(a.at(i) == b.at(i)){
                if(i == a.size() - 1){
                    flg = 'e';
                }            
            }else if(a.at(i) > b.at(i)){
                flg = 'g';
                break;
            }else if(a.at(i) < b.at(i)){
                flg = 'l';
                break;
            }
        }
    }else{
        if(a.size() > b.size()){
            flg = 'g';
        }else{
            flg = 'l';
        }
    }

    switch(flg){
        case 'g' :
            std::cout << "GREATER" << std::endl;
            break;
        case 'l' :
            std::cout << "LESS" << std::endl;
            break;
        case 'e' :
            std::cout << "EQUAL" << std::endl;
            break;
    }
    
    return 0;
}