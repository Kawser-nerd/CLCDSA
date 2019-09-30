#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  int a,b,c,d;
  std::cin >> a >> b >>c >> d;

  if(a*b>c*d) std::cout << a*b << endl;
  else std::cout << c*d << endl;
  return 0;
}