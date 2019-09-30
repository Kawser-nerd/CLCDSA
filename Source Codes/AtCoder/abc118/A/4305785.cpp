#include <iostream>
using namespace std;

int main(){
  int a, b, ans;
  cin >> a >> b;
  if(b % a == 0) ans = a + b;
  else ans = b - a;
  cout << ans << endl;
  return 0;
}