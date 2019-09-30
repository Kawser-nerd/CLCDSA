#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n)  FOR(i, 0, n)
#define ASC(c) sort((c).begin(), (c).end())
#define DESC(c) sort((c).begin(), (c).end(), greater<int>())

#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

typedef long long ll;
typedef unsigned long long ull;
struct edge { int u, v; ll w; };
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
  int n, m; cin >> n >> m;
  vector<pair<int, int>> p(n);
  REP(i, n) {
    int a, b; cin >> a >> b;
    p[i] = make_pair(a, b);
  }
  sort(p.begin(), p.end(), [](pair<int, int> a, pair<int, int> b) -> bool{ return a.first < b.first; });

  ll ans = 0, total = 0;
  REP(i, n) {
    total += p[i].second;
    if (m <= total) {
      ans += p[i].first * (p[i].second - (total - m));
      break;
    }
    else ans += p[i].first * p[i].second;
  }
  cout << ans << endl;
}