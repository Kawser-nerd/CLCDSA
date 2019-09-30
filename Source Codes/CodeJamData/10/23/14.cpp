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

typedef long long ll;

int mod = 100003;
int choose[500][500];

int ans[501][500];

int main(void)
{
  choose[0][0] = 1;
  for (int n = 1; n < 500; n++) {
    choose[n][0] = 1;
    for (int k = 1; k <= n; k++)
      choose[n][k] = (choose[n-1][k-1] + choose[n-1][k]) % mod;
  }
  for (int n = 2; n <= 500; n++) {
    ans[n][1] = 1;
    for (int k = 2; k <= n-1; k++) {
      for (int k2 = 1; k2 < k; k2++) { // k is the k2-th number
	ans[n][k] = (ans[n][k] + ans[k][k2] * (ll) choose[n-k-1][k-k2-1]) % mod;
      }
    }
  }
  
  int C; cin >> C;
  for (int c = 1; c <= C; c++) {
    int n; cin >> n;
    int ret = 0;
    for (int k = 1; k <= n-1; k++)
      ret += ans[n][k];
    printf("Case #%d: %d\n", c, ret % mod);
  }
}
