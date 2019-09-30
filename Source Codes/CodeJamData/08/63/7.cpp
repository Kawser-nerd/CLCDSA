#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

#define all(c) ((c).begin()), ((c).end()) 
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end()) 
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long ll;

const ll mil = 1000000;
const double EPS = 1E-12;

int M, X;
double P;

int N;
double dp[20][1 << 17];

inline double DP(int r, int n) {
  if (n < 0) return 0.0;
  else if (N <= n) return 1.0;
  else return dp[r][n];
}

int main() {
  int C;
  scanf("%d", &C);

  for (int t = 1; t <= C; t++) {
    fprintf(stderr, "%d / %d\n", t, C);
    scanf("%d%lf%d", &M, &P, &X);

    N = (1 << M); // inclusive
    memset(dp, 0, sizeof(dp));
    dp[0][N] = 1.0;
    for (int r = 1; r <= M; r++) {
      for (int i = 0; i <= N; i++) {
        double ma = 0.0;
        if (DP(r - 1, i + i) < EPS) {
          dp[r][i] = 0.0;
          continue;
        }
        else {
          for (int j = 0; j <= i; j++) { // donokurai kakeru!?
            ma = max(P * DP(r - 1, i + j) + (1 - P) * DP(r - 1, i - j), ma);
            //printf("%.2f ", P * DP(r - 1, i + j) + (1 - P) * DP(r - 1, i - j));
          }
          dp[r][i] = ma;
        }
        //puts("");
      }
      //puts("");
    }

    double res = 0.0;
    for (int i = 0; i <= N; i++) {
      if (X * (ll)N >= mil * i) res = max(dp[M][i], res);
    }
    printf("Case #%d: %.10f\n", t, res);
  }
}

