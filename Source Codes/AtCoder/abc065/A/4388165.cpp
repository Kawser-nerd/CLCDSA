#include <iostream>
using namespace std;

int main(){
  int a, b, x;
  cin >> x >> a >> b;
  if(b<=a)cout << "delicious";
  else if(b<=a+x)cout << "safe";
  else cout << "dangerous";
  return 0;
}