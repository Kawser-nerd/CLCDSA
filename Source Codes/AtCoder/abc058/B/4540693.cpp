#include <iostream>

int main(){
    std::string o, e;
    std::cin >> o >> e;

    std::string str = "";
    for(int i = 0; i < o.size(); ++i){
        if(i == e.size()){
            str += o.at(i);
        }else{
            str += o.at(i);
            str += e.at(i);
        }
    }

    std::cout << str << std::endl;

    return 0;
}