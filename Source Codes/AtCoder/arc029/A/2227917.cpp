#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,a,n) for(int i = (a); i < (n); ++i)
#define REP(i,n) FOR(i,0,n)
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define INF 100000000


int n;
int t[4];
int main() {
  cin >> n;
  REP(i,n) cin >> t[i];
  int min = INF;
  for (int i = 0; i < (1 << (n-1)); i++) {
    int sum1 = 0, sum2 = 0;
    for (int j = 0; j < n; j++) {
      if (1 & i >> j) sum1 += t[j];
      else sum2 += t[j];
    }
    chmin(min, max(sum1, sum2));
  }
  cout << min << endl;
  return 0;
}