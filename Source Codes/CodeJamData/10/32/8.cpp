#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define CLEAR(a) memset(a, 0, sizeof(a))

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int C = 1; C <= T; C++) {
    long long d, h, c;
    cin >> d >> h >> c;
    int n = -1;
    while (d < h) {
      d *= c;
      n++;
    }
    cerr << n << endl;
    int r = 10;
    while (r >= 0 && (n&(1<<r)) == 0)
      r--;
    cout << "Case #" << C << ": " << r+1 << endl;
  }
}
