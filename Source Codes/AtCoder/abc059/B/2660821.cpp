#include <iostream>
#include <string>
#include <cmath>

int main()
{
  std::string s, t;
  std::cin >> s >> t;

  int ss = s.size();
  int ts = t.size();

  int len = std::abs( ss - ts );
  if( ss > ts ) {
    for( int i = 0; i < len; i++ ) {
      t = "0" + t;
    }
  }
  else {
    for( int i = 0; i < len; i++ ) {
      s = "0" + s;
    }
  }

  std::string a;
  if( s > t ) {
    a = "GREATER";
  }
  if( s < t ) {
    a = "LESS";
  }
  if( s == t ) {
    a = "EQUAL";
  }

  std::cout << a << std::endl;

  return 0;
}