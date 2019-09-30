#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,a,n) for(int i = (a); i < (n); ++i)
#define REP(i,n) FOR(i,0,n)
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int N, C;
int s[100000], t[100000], c[100000];
int tt[200002];
int sm[200002];

int main() {
  cin >> N >> C;
  REP(i, N) cin >> s[i] >> t[i] >> c[i];
  REP(i, C+1) {
    REP(j,200002) tt[j] = 0;
    REP(j, N) if (c[j]==i) tt[s[j]*2-1]++, tt[t[j]*2]--;
    FOR(j,1,200002) tt[j] += tt[j-1];
    REP(j,200002) if (tt[j] > 0) sm[j]++;
  }
  int max = 0;
  REP(i,200002) chmax(max,sm[i]);
  cout << max << endl;
  return 0;
}