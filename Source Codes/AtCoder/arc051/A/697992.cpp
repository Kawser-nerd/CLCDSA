#include <iostream>

using namespace std;;
using ll = long long;

ll sq(ll x) { return x * x; }

int main() {
  ll x1, y1, r, x2, y2, x3, y3;
  cin>>x1>>y1>>r>>x2>>y2>>x3>>y3;

  if (x2 <= x1 - r && x1 + r <= x3 &&
      y2 <= y1 - r && y1 + r <= y3) {
    cout<<"NO"<<endl;
  } else {
    cout<<"YES"<<endl;
  }

  if (sq(x2 - x1) + sq(y2 - y1) <= r * r &&
      sq(x3 - x1) + sq(y2 - y1) <= r * r &&
      sq(x2 - x1) + sq(y3 - y1) <= r * r &&
      sq(x3 - x1) + sq(y3 - y1) <= r * r) {
    cout<<"NO"<<endl;
  } else {
    cout<<"YES"<<endl;
  }

  return 0;
}