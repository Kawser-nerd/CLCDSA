#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
template<class T> using vv=vector<vector< T > >;

vvi g;
deque<bool> checked;

int max_node;

vi d;

int n, m;

void dijkstra(int s) {
  d.assign(n, -1);
  priority_queue<pii, vector<pii>, less<pii> > q;
  d[s] = s;
  q.push(make_pair(s, s));

  while (!q.empty()) {
    auto p = q.top();
    q.pop();
    int v = p.second;
    if (d[v] > p.first) {
      continue;
    }
    for (auto e : g[v]) {
      if (d[e] < min(d[v], e)) {
        d[e] = min(d[v], e);
        q.push(make_pair(d[e], e));
      }
    }
  }
}

int main() {
  int s;
  scanf("%d %d %d", &n, &m, &s);
  s -= 1;
  g.resize(n);
  rep (i, m) {
    int u, v;
    scanf("%d %d", &u, &v);
    u -= 1; v -= 1;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dijkstra(s);

  rep (i, n) {
    if (d[i] == i) {
      printf("%d\n", i + 1);
    }
  }

  return 0;
}