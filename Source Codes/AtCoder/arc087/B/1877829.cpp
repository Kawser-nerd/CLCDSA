#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

char s[8888];
vector<int> a[2];
int x, y;

bool solve(int p, int s, map<int, int> dp[8888], vector<int>& q, int l) {
  if (p == int(q.size())) return s == l;
  if (dp[p].count(s)) return false;
  dp[p][s] = true;
  return solve(p+1, s+q[p], dp, q, l) || solve(p+1, s-q[p], dp, q, l);
}

int main(void) {
  scanf("%s", s);
  scanf("%d%d", &x, &y);
  int p = 0;
  for (int i = 0; s[p]; i = 1 - i) {
    int k = 0;
    while (s[p] == 'F') ++p, ++k;
    a[i].push_back(k);
    ++p;
  }

  /*
  for (int i = 0; i < 2; i++) {
    for (auto&& x : a[i]) {
      printf("%d ", x);
    }
    puts("");
  }
  */

  bool ok = true;
  map<int, int> dp[8888];
  ok &= solve(1, a[0][0], dp, a[0], x);
  if (ok) {
    for (int i = 0; i < 8888; i++) {
      dp[i].clear();
    }
    ok &= solve(0, 0, dp, a[1], y);
  }
  puts(ok ? "Yes" : "No");
  return 0;
}