#include <iostream>

int main()
{
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << ( b - a == c - b ? "YES" : "NO" ) << std::endl;
  return 0;
}