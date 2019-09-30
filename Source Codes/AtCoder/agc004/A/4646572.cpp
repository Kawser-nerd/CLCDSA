#include <iostream>
using namespace std;
#define ll long long

int main () {
  ll a, b, c;
  cin >> a >> b >> c;
  ll aa = abs(b * c * (a / 2 - (a - a / 2)));
  ll bb = abs(c * a * (b / 2 - (b - b / 2)));
  ll cc = abs(a * b * (c / 2 - (c - c / 2)));
  cout << min(aa, min(bb, cc)) << endl;
}