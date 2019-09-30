#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,a,n) for(int i = (a); i < (n); ++i)
#define REP(i,n) FOR(i,0,n)
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int h, w;
int c[10][10];
int main() {
  cin >> h >> w;
  REP(i,10) REP(j,10) cin >> c[i][j];
  REP(i,10) REP(j,10) REP(k,10) {
    chmin(c[j][k], c[j][i]+c[i][k]);
  }
  int a, ans = 0;
  REP(i,h) REP(j,w) {
    cin >> a;
    if (a >= 0) ans += c[a][1];
  }
  cout << ans << endl;
  return 0;
}