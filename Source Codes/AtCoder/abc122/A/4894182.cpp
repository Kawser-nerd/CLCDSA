#include <iostream>
#include <map>

int main(){
  char b;
  std::cin >> b;
  
  std::map<char,char> m = 
  {
    {'A','T'},
    {'T','A'},
    {'C','G'},
    {'G','C'},
  };
    std::cout << m[b] << std::endl;
}