#include <iostream>
using namespace std;
int main(){
  int a;
  int b;
  int c;

  cin >> a >> b >> c ;
  int d = (a*b + b* c + c * a) * 2;
  std::cout << d <<endl;
  return 0;
}