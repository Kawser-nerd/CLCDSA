#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

int main() {
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    cout << "Case #" << ta << ":";
    lli k, c, s;
    cin >> k >> c >> s;
    if (s*c < k) {
      cout << " IMPOSSIBLE" << endl;
    } else {
      lli x=0;
      for (lli i=0; i<k; ++i) {
        x = x*k+i;
        if ((i+1)%c==0 || i==k-1) {
          cout << " " << x+1;
          x=0;
        }
      }
      cout << endl;
    }
  }
}