#include <iostream>
using namespace std;

typedef long long int lli;

int main() {
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    cout << "Case #" << ta << ":" << endl;
    lli n, j;
    cin >> n >> j; 
    for (lli i = 0; i<j; ++i) {
      cout << "1001";
      for (lli p=n-9; p>=0; --p) {
        cout << (i&(1<<((p%3)+(p/6)*3)) ? '1' : '0');
      }
      cout << "1001 3 2 5 2 7 2 3 2 7" << endl;
    }
  }
}

/*
1  1
 1  1
  1  1
...
*/