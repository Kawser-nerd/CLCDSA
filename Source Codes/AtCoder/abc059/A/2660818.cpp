#include <iostream>
#include <algorithm>
#include <string>

int main()
{
  std::string a, b, c;
  std::cin >> a >> b >> c;

  std::string s;
  s.push_back( a[ 0 ] );
  s.push_back( b[ 0 ] );
  s.push_back( c[ 0 ] );

  std::transform( s.cbegin(), s.cend(), s.begin(), toupper );

  std::cout << s << std::endl;
  return 0;
}