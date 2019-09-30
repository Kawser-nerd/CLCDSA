#include <iostream>
     
    int main()
    {
      int A, B;
      std::cin >> A >> B;
      if (A == 2 || B == 2) {
        std::cout << "No" << std::endl;
      } else {
        std::cout << "Yes" << std::endl;
      }
    }