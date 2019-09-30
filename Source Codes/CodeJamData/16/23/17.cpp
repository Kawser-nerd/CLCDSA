/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct Index {
  unordered_map<string, int> u;
  int get( const string &s ) {
    auto it = u.insert(make_pair(s, (int)u.size()));
    return it.first->second;      
  }
  int n() { return u.size(); }
};

void solve() {
  Index a, b;
  string sa, sb;
  int n;
  cin >> n;
  vector<int> c[n];
  forn(i, n) {
    cin >> sa >> sb;
    c[a.get(sa)].push_back(b.get(sb));
  }
  int cc = 1;
  vector<int> u(n), pa(n, -1);
  function<int(int)> dfs = [&]( int v ) {
    u[v] = cc;
    for (int x : c[v])
      if (pa[x] == -1 || (u[pa[x]] != cc && dfs(pa[x]))) {
        pa[x] = v;
        return 1;
      }
    return 0;
  };
  forn(i, n)
    if (dfs(i))
      cc++;
  printf("%d\n", n - (a.n() + b.n() - (cc - 1)));
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}
