#include<iostream>

double W,H;

int main(){

    std::cin>>W>>H;

    if(W/H<1.5)
    std::cout<<"4:3"<<std::endl;
    else
    std::cout<<"16:9"<<std::endl;

    return 0;
}