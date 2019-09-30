#include <iostream>
#include <algorithm>

int main(){
    std::string str;
    std::cin >> str;

    int inputSize = str.size();

    std::sort(str.begin(), str.end());
    str.erase(std::unique(str.begin(), str.end()), str.end());

   if(inputSize == str.size()){
       std::cout << "yes" << std::endl;
   }else{
       std::cout << "no" << std::endl;
   }

   return 0;
}