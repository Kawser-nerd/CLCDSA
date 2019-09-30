#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstdint>
#include <numeric>

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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N;
  cin >> N;
  vector<int> xs(N);
  rep (i, N) cin >> xs[i];

  //int min_x = min(xs.begin(), xs.end());
  //int max_x = max(xs.begin(), xs.end());

  int max_i = 0, min_i = 0;
  rep (i, 1, N) {
    int x = xs[i];
    if (x < xs[min_i]) min_i = i;
    if (x > xs[max_i]) max_i = i;  
  }

  int max_x = xs[max_i], min_x = xs[min_i];
  bool pos = abs(max_x) >= abs(min_x);

  //cout << "max: " << max_x << " min: " << min_x << endl; 
  cout << 2*N-2 << endl;

  if (pos) {
    rep (i, N) {
      if (i == max_i) continue;
      cout << max_i+1 << " " << i+1 << "\n";
      //xs[i] += xs[max_i];
    }
    rep (i, N-1) {
      cout << i+1 << " " << i+2 << "\n";
      //xs[i+2] += xs[i+1];
    }
  } else {
    rep (i, N) {
      if (i == min_i) continue;
      cout << min_i+1 << " " << i+1 << "\n";
    }
    rrep (i, N-1) {
      cout << i+2 << " " << i+1 << "\n";
    }  
  }

  //rep (i, N) cout << xs[i] << " ";
  cout << flush;

  return 0;
}