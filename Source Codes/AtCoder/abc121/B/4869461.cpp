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
  int n, m, c; cin >> n >> m >> c;
  vector<int> b(20);
  vector<vector<int>> a(20, vector<int>(20));

  REP(i, m) cin >> b[i];
  REP(i, n) { 
    REP(k, m) cin >> a[i][k];
  }

  int ans = 0;
  REP(i, n) {
    int sum = 0;
    REP(k, m) {
      sum += a[i][k] * b[k];
    }
    if (sum + c > 0) ans++;
  }
  cout << ans << endl;
}