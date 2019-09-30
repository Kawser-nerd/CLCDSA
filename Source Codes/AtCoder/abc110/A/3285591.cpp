#include <iostream>
#include <numeric>
#include <vector>

int main()
{
  int a,b,c;
  std::cin >> a>>b>>c;
  
  int v;
       if (a <= b && b <= c) v = c*10+b+a;
  else if (a <= c && c <= b) v = b*10+c+a;
  else if (b <= a && a <= c) v = c*10+b+a;
  else if (b <= c && c <= a) v = a*10+c+b;
  else if (c <= a && a <= b) v = b*10+c+a;
  else /*if (c <= b && b <= a)*/ v = a*10+b+c;

  std::cout << v << std::endl;
}