#include <iostream>
#include <string>
#include <cmath>

int main()
{
  std::string o, e;
  std::cin >> o >> e;

  int size = ceil( ( o.size() + e.size() ) / 2.0 );
  for( int i = 0; i < size; i++ ) {
    if( o[ i ] != 0 ) {
      std::cout << o[ i ];
    }
    if( e[ i ] != 0 ) {
      std::cout << e[ i ];
    }
  }

  std::cout << std::endl;
  return 0;
}