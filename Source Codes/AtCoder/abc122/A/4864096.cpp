#include <iostream>
 
int main()
{
  char a;
  
  std::cin >> a;
  
  if (a == 'A') {
    std::cout << "T" << std::endl;
  }
  
  if (a == 'T') {
    std::cout << "A" << std::endl;
  }
  
  if (a == 'G') {
    std::cout << "C" <<std::endl;
  }
  
  if (a == 'C') {
    std::cout << "G" << std::endl;
    
  }
  
  return 0;
}