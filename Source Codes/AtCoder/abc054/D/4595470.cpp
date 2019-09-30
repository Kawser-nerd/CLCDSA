#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

void OutputError(std::string s) {
  cerr << "\033[93m" << s << "\033[m" << endl;
  return;
}

struct Drug {
  int64_t a;
  int64_t b;
  int64_t c;
  Drug(int pa, int pb, int pc) {
    a = pa;
    b = pb;
    c = pc;
  }
};

signed main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int64_t n, ma, mb;
  cin >> n >> ma >> mb;
  const int64_t MAX_C = n * 100;
  const int64_t MAX_A = n * 10, MAX_B = n * 10;
  std::vector<Drug> drug;
  for (int i = 0; i < n; i++) {
    int m1, m2, m3;
    cin >> m1 >> m2 >> m3;
    drug.push_back(Drug(m1, m2, m3));
  }
  int64_t dp[MAX_A + 1][MAX_B + 1][n];
  for (int i = 0; i < MAX_A + 1; i++) {
    for (int j = 0; j < MAX_B + 1; j++) {
      for (int k = 0; k < n; k++) {
        dp[i][j][k] = INT64_MAX / 3;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    dp[0][0][i] = 0;
  }

  dp[drug[0].a][drug[0].b][0] = drug[0].c;
  // cout << dp[2][2][0] << endl;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < MAX_A + 1; j++) {
      for (int k = 0; k < MAX_B + 1; k++) {
        if (j - drug[i].a >= 0 && k - drug[i].b >= 0) {
          dp[j][k][i] =
              std::min(dp[j][k][i - 1],
                       dp[j - drug[i].a][k - drug[i].b][i - 1] + drug[i].c);
        } else {
          dp[j][k][i] = dp[j][k][i - 1];
        }
      }
    }
    // cout << dp[2][2][i] << endl;
  }
  // for (int j = 0; j < MAX_A + 1; j++) {
  //   for (int k = 0; k < MAX_B + 1; k++) {
  //     if (dp[j][k][n - 1] != INT64_MAX / 3)
  //       cerr << j << "\t" << k << "\t" << n - 1 << "\t" << dp[j][k][n - 1]
  //            << endl;
  //     if (dp[j][k][n - 1] == 117) {
  //       cerr << "gweagawe" << endl;
  //     };
  //   }
  // }

  int search_a = ma, search_b = mb;
  int64_t result = INT64_MAX / 3;
  bool found     = false;
  while (search_a <= MAX_A && search_b <= MAX_B) {
    if (result > dp[search_a][search_b][n - 1]) {
      result = dp[search_a][search_b][n - 1];
      found  = true;
    }
    search_a += ma;
    search_b += mb;
  }
  if (found) {
    cout << result << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}