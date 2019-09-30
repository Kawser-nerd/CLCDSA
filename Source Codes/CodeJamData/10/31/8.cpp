#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define CLEAR(a) memset(a, 0, sizeof(a))

const int maxn = 1010;

int a[maxn];
int b[maxn];

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int C = 1; C <= T; C++) {
    int n;
    cin >> n;
    REP(i, n)
      cin >> a[i] >> b[i];

    int res = 0;
    REP(i, n)
      REP(j, i) {
	if (a[i] < a[j] && b[i] > b[j])
	  res++;
	if (a[i] > a[j] && b[i] < b[j])
	  res++;
      }

    cout << "Case #" << C << ": " << res << endl;
  }
}
