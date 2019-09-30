#include <iostream>
     
    int main(int argc, char* argv[])
    {
      int a, b;
      std::cin >> a;
      std::cin >> b;
      
      if (b % a == 0) {
        std::cout << a + b << std::endl;
      }
      else {
        std::cout << b - a << std::endl;
      }
    }