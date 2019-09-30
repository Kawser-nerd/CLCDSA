#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <numeric>
#include <complex>

using namespace std;

char needs[55][55];

int sq(int x) { return x*x; };

int main(void) {
  int T; cin >> T;
  for (int c = 1; c <= T; c++) {
    int ans = 0;
    int n; cin >> n;
    vector <int> x(n), y(n), r(n), s(n);
    for (int i = 0; i < n; i++)
      cin >> x[i] >> y[i] >> r[i] >> s[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
	needs[i][j] = (sq(x[i]-x[j]) + sq(y[i]-y[j]) <= sq(r[i]));
    int N = 1<<n;
    for (int mask = 0; mask < N; mask++) {
      bool ok = true;
      for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	  if (((mask>>i)&1) && !((mask>>j)&1) && needs[i][j])
	    ok = false;
      if (!ok) continue;
      int score = 0;
      for (int i = 0; i < n; i++)
	if ((mask>>i)&1)
	  score += s[i];
      ans = max(ans, score);
    }
    printf("Case #%d: %d\n", c, ans);
  }
  return 0;
}
