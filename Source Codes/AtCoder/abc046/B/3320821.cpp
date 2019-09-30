#include<iostream>
#include<cmath>
int main(){

  int numB;
  int numC;
  int x;

  std::cin>>numB>>numC;
  x=numC*std::pow(numC-1,numB-1);
  std::cout<<x<<std::endl;
  
}