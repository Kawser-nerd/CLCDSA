#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <tuple>
#include <list>
#include <deque>
#include <stack>
#include <complex>
#include <functional>
#include <regex>
#include <map>
#include <numeric>

using namespace std;

#define REP(i,a,b) for(int i=(a); i<(b); ++(i))
#define rep(i,n) REP(i,0,n)

const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

using ll = long long;
using ld = long double;
using ull = unsigned long long;

const int PI = acos(-1);
const int INF = numeric_limits<int>::infinity() / 2;
const ll INFLL = numeric_limits<ll>::infinity() / 2;

ull gcd(ull a, ull b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ull lcm(ull a, ull b) {
  return a / gcd(a, b) * b;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N; cin >> N;
  vector<ull> T(N);
  rep(i, N) cin >> T[i];
  ull ans = T[0];
  REP(i, 1, N)
    ans = lcm(ans, T[i]);
  cout << ans << endl;
  return 0;
}