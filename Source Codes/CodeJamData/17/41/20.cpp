#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using ld = long double;

constexpr int nax = 102;
constexpr int infty = 1000 * 1000 * 1000 + 5;
constexpr int mod = 1000 * 1000 * 1000 + 7;

int dp[nax][nax][nax][nax];

int przyp() {
  int n, p;
  int r[4] = {0, 0, 0, 0};
  scanf("%d%d", &n, &p);
  while (n--) {
    int x;
    scanf("%d", &x);
    r[x % p]++;
  }
  dp[0][0][0][0] = 0;
  for (int sum = 1; sum <= r[0] + r[1] + r[2] + r[3]; sum++) {
    for (int a = 0; a <= sum and a <= r[0]; a++) {
      for (int b = 0; b <= sum - a and b <= r[1]; b++) {
        for (int c = 0; c <= sum - a - b and c <= r[2]; c++) {
          const int d = sum - a - b - c;
          if (d > r[3]) continue;
          const int r = (a * 0 + b * 1 + c * 2 + d * 3) % p;
          int& wyn = dp[a][b][c][d] = 0;
          if (a > 0) wyn = max(wyn, dp[a - 1][b][c][d] + (r == 0));
          if (b > 0) wyn = max(wyn, dp[a][b - 1][c][d] + (r == 1));
          if (c > 0) wyn = max(wyn, dp[a][b][c - 1][d] + (r == 2));
          if (d > 0) wyn = max(wyn, dp[a][b][c][d - 1] + (r == 3));
        }
      }
    }
  }
  return dp[r[0]][r[1]][r[2]][r[3]];
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: %d\n", i, przyp());
  }
  return 0;
}
