#include <iostream>

int main()
{
    int A,B,C;
    std::cin >> A >> B >> C;
    bool check = false;
    if(A == 5){
        if(B == 5 || C ==5){
            if(B == 7 || C ==7){
                check = true;
            }
        }
    } 
    else if(B == 5){
        if(A == 5 || C ==5){
            if(A == 7 || C ==7){
                check = true;
            }
        }
    }
    if(check){
        std::cout << "YES" << std::endl;
    }
    else{
        std::cout << "NO" << std::endl;
    }
}