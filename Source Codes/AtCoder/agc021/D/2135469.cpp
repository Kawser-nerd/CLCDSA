/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-25 19:18:18
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>   // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set>
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

string S;
int N;
int K;

int DP[310][310][310];
int DP2[310][26];

int calc(int l, int r, int k) {
  if (r - l <= 2 * k + 1)
    return r - l;
  if (DP[l][r][k] != -1)
    return DP[l][r][k];
  int ans = 0;
  if (l+1 <= r-1 && k-1 >= 0)
    ans = max(ans, calc(l + 1, r - 1, k - 1) + 2);
  if (l <= r-1)
    ans = max(ans, calc(l, r - 1, k));
  int nl = DP2[l][S[r - 1] - 'a'] + 1;
  if (nl <= r-1)
    ans = max(ans, calc(nl, r - 1, k) + 2);
  DP[l][r][k] = ans;
#if DEBUG == 1
  cerr << "DP[" << l << "][" << r
       << "][" << k << "] = " << ans << endl;
#endif
  return ans;
}

int main()
{
  cin >> S >> K;
  N = S.size();
  fill(&DP[0][0][0], &DP[0][0][0] + 310 * 310 * 310, -1);
  for (auto j = 0; j < 26; j++)
  {
    DP2[N][j] = N;
  }
  for (auto i = N-1; i >= 0; i--)
  {
    for (auto j = 0; j < 26; j++)
    {
      DP2[i][j] = DP2[i + 1][j];
    }
    DP2[i][S[i] - 'a'] = i;
  }
  cout << calc(0, N, K) << endl;
}