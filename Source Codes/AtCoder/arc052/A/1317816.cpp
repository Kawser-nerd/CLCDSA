#include <iostream>
std::string S;
int main(void){
    std::cin >> S;
    for(auto it=S.begin(), _END=S.end(); it != _END; ++it){
        if( *it >= '0' && *it <= '9' ){
            std::cout << *it;
            if( it+1 == _END ) break;
            if( *(it+1) >= '0' && *(it+1) <= '9' ){
                std::cout << *(it+1);
            }
            std::cout << "\n";
            break;
        }
    }
}