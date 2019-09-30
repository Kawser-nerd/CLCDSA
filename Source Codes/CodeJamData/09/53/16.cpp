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

int readint() { 
  int i, j, s;
  while (!isdigit(i = getchar()) && i != '-');
  if (i == '-') { s = -1; j = 0; }
  else { s = 1; j = i - '0'; }
  while (isdigit(i = getchar())) j = ((j << 1) + (j << 3) + (i - '0'));
  return j * s;
}

int N, Y;
vector<pair<int, int> > pts;

int lim;
set<string> vis[1010];
void saiki(int k, string &col) {
  if (k == N) throw "done";

  if (vis[k].count(col)) return;
  vis[k].insert(col);

  int y = pts[k].second;
  for (char c = 'a'; c < 'a' + lim; c++) {
    if (col[y - 1] == c) continue;
    if (col[y] == c) continue;
    if (col[y + 1] == c) continue;

    swap(col[y], c);
    saiki(k + 1, col);
    swap(col[y], c);
  }
}

int main() {
  int cases = readint();
  rep (ca, cases) {
    N = readint();
    int ymi = 9876, yma = 0;

    pts.clear();
    rep (i, N) {
      int x = readint();
      int y = readint();
      pts.pb(mp(x, y));

      ymi = min(ymi, y);
      yma = max(yma, y);
    }
    rep (i, N) pts[i].second -= (ymi - 1);
    Y = yma - ymi + 3;

    sort(all(pts));
    reverse(all(pts));
    for (lim = 1; lim <= 3; lim++) {
      string c(Y, '?');
      try {
        rep (i, N) vis[i].clear();
        saiki(0, c);
      } catch (...) {
        break;
      }
    }

    printf("Case #%d: %d\n", ca + 1, lim);
  }

  return 0;
}
