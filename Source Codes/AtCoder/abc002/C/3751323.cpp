#include <iostream>
using namespace std;

double abc(int x) {
  if (x > 0) {
    return (double) x;  
  }  
  return (double) x * -1;
}

int main () {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  c = c - a;
  d = d - b;
  e = e - a;
  f = f - b;
  cout << fixed << (double) abc(c * f - e * d) / 2 << endl;  
}