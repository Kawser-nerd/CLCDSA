#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> > v;

int nnodememo[1001][1001];
int nnode(int x, int prev) {
  int& ret = nnodememo[x][prev];
  if (ret != -1) return ret;
  ret = 1;
  for (int i = 0; i < v[x].size(); i++) if (v[x][i] != prev)
    ret += nnode(v[x][i], x);
  return ret;
}

int memo[1001][1001];
int doit(int x, int prev) {
  int& ret = memo[x][prev];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = 0; i < v[x].size(); i++) if (v[x][i] != prev)
    ret += nnode(v[x][i], x);
  int m1 = 1000000, m2 = 1000000;
  for (int i = 0; i < v[x].size(); i++) if (v[x][i] != prev) {
    int m = doit(v[x][i], x) - nnode(v[x][i], x);
    if (m < m1) {
      m2 = m1;
      m1 = m;
    } else if (m < m2) {
      m2 = m;
    }
  }
  ret = min(ret, ret+m1+m2);
  return ret;
}

main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    cout << "Case #" << prob++ << ": ";

    int N;
    cin >> N;
    v = vector<vector<int> >(N+1);
    for (int i = 0; i < N-1; i++) {
      int X, Y;
      cin >> X >> Y;
      v[X].push_back(Y);
      v[Y].push_back(X);
    }

    memset(nnodememo, -1, sizeof(nnodememo));
    memset(memo, -1, sizeof(memo));
    int ret = 1000000;
    for (int i = 1; i <= N; i++) ret = min(ret, doit(i, 0));

    cout << ret;
    cout << endl;
  }
}
