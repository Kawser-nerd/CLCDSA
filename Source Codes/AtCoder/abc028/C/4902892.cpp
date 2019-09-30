#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  cout << max(a+d+e, b+c+e) << endl;
  return 0;
}