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

int n, A, B, C;

int dfs(vector<int> l, int cur, int a, int b, int c) {
  if (cur == n) {
    if (min({a, b, c}) > 0) return abs(a - A) + abs(b - B) + abs(c - C) - 30;
    else return pow(10, 9);
  }
  int ret0 = dfs(l, cur + 1, a, b, c);
  int ret1 = dfs(l, cur + 1, a + l[cur], b, c) + 10;
  int ret2 = dfs(l, cur + 1, a, b + l[cur], c) + 10;
  int ret3 = dfs(l, cur + 1, a, b, c + l[cur]) + 10;
  return min({ret0, ret1, ret2, ret3});
}

int main() {
  cin >> n >> A >> B >> C;
  vector<int> l(n);
  REP(i, n) cin >> l[i];
  cout <<  dfs(l, 0, 0, 0, 0) << endl;
}