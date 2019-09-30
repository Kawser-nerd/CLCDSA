#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <cmath>
using namespace std;
using ll = long long;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define FOR(i,a,n) for(int i = (a); i < (n); ++i)
#define RFOR(i,a,n) for(int i = (a)-1; i >= (n); --i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,n,0)
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define abs(x) ((x) > 0 ? (x) : (-(x)))

int mid(int x, int y, int z) {
  int minv = min(x, min(y, z));
  if (minv == x) return min(y,z);
  else if (minv == y) return min(x,z);
  else return min(x,y);
}


int main() {
  int n; cin >> n;
  vector<int> a(n+2);
  FOR(i,1,n+1) cin >> a[i];
  int route = 0;
  FOR(i,1,n+2) route += abs(a[i] - a[i-1]);
  FOR(i,1,n+1) {
    if (mid(a[i-1], a[i], a[i+1]) == a[i]) {
      cout << route << endl;
    } else if (mid(a[i-1], a[i], a[i+1]) == a[i-1]) {
      cout << route - 2*abs(a[i] - a[i-1]) << endl;
    } else {
      cout << route - 2*abs(a[i+1] - a[i]) << endl;
    }
  }
  return 0;
}