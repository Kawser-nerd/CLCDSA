#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
#include <cmath>
#include <string> 
#include <ctime>

using namespace std;

#undef Fdg_Home

long long dp[67][2][2][2];
vector<int> A, B, C;

long long solve() {
  memset(dp, 0, sizeof(dp));
  dp[0][0][0][0] = 1;
  int n = A.size();

  for (int i = 0; i < n; ++i) {
    for (int a = 0; a < 2; ++a)
      for (int b = 0; b < 2; ++b)
        for (int c = 0; c < 2; ++c)
          if (dp[i][a][b][c]) {
            for (int aa = 0; aa <= (a ? 1 : A[i]); ++aa)
              for (int bb = 0; bb <= (b ? 1 : B[i]); ++bb)
                for (int cc = 0; cc <= (c ? 1 : C[i]); ++cc)
                  if ((aa & bb) == cc) {
                    dp[i + 1][a || (aa < A[i])][b || (bb < B[i])][c || (cc < C[i])] += dp[i][a][b][c];
                  }
          }
  }

  long long ans = 0;
  for (int a = 0; a < 2; ++a)
    for (int b = 0; b < 2; ++b)
      for (int c = 0; c < 2; ++c)
        ans += dp[n][a][b][c];
  return ans;
}

void solveTest(int CS) {
  printf("Case #%d: ", CS);
  int a, b, k;
  cin >> a >> b >> k;
  --a; --b; --k;
  A.clear(); B.clear(); C.clear();
  while (a > 0) {
    A.push_back(a % 2);
    a /= 2;
  }
  while (b > 0) {
    B.push_back(b % 2);
    b /= 2;
  }
  while (k > 0) {
    C.push_back(k % 2);
    k /= 2;
  }
  int sz = max(A.size(), max(B.size(), C.size()));
  for (int i = 0; i < sz; ++i) {
    if (A.size() == i) A.push_back(0);
    if (B.size() == i) B.push_back(0);
    if (C.size() == i) C.push_back(0);
  }
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  reverse(C.begin(), C.end());
  long long ans = solve();
  printf("%lld\n", ans);
}

int main() {
#ifndef Fdg_Home
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  scanf("%d\n", &T);
  for (int test = 1; test <= T; ++test) {
    solveTest(test);
  }
  return 0;
}