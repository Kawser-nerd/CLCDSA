#include<algorithm>
#include<cmath>
#include<cstdint>
#include<cstdio>
#include<functional>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<(b); ++i)
#define rep(i,n) for(int i=0; i<n; ++i)
#define all(v) begin(v), end(v)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const double PI = acos(-1.0);

int main() {
  std::ios::sync_with_stdio(false);

  int a, b;
  while(cin >> a >> b) {
    int cnt = 0;
    while(abs(b - a)) {
      int d[6] = {a + 10, a - 10, a + 5, a - 5, a + 1, a - 1};
      int best = a;
      rep(i, 6) {
        if (0 <= d[i] && abs(b - d[i]) < abs(b - best)) {
          best = d[i];
        }
      }
      a = best;
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}