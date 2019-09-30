#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstdint>

#define _rep_overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _rep_overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

#define _rrep_overload3(_1,_2,_3,name,...) name
#define _rrep(i,n) rrepi(i,n,0)
#define rrepi(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _rrep_overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)

using namespace std;

// Globals

int main() {
  int n;
  cin >> n;
  vector<int> xs(n);
  rep (i, n) cin >> xs[i];

  int left = 0;
  long ans = 0;
  int state = 0;
  
  rep (right, n) {
    for ( ; (xs[right] & state) != 0; state -= xs[left], ++left);
    state = xs[right] | state;
    ans += right - left + 1;
    // printf("%d, %d : %d\n", left, right, state);
  }

  cout << ans << endl;

  return 0;
}