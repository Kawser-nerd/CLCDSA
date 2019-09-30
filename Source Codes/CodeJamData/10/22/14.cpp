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

int main(void)
{
  int C; cin >> C;
  for (int c = 1; c <= C; c++) {
    int ans = 0;
    int N, K, B, T; cin >> N >> K >> B >> T;
    vector <int> X(N), V(N);
    for (int i = 0; i < N; i++)
      cin >> X[i];
    for (int i = 0; i < N; i++)
      cin >> V[i];
    int bad = 0;
    for (int i = N-1; i >= 0; i--) {
      if ((B-X[i]+V[i]-1)/V[i] > T)
	bad++;
      else {
	ans += bad;
	K--;
      }
      if (K == 0) break;
    }
    if (K == 0)
      printf("Case #%d: %d\n", c, ans);
    else
      printf("Case #%d: IMPOSSIBLE\n", c);
  }
}
