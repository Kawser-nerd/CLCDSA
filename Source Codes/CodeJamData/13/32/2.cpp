// cool: http://autumn_fest.contest.atcoder.jp/tasks/autumn_fest_05
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))

void solve();
int main() {
  int test_case; cin >> test_case;
  REP(t, test_case) {
    printf("Case #%d: ", t+1);
    solve();
  }
}
//-------------------------------

void solve() {
  ll x, y;
  cin >> x >> y;

  // min step?
  for (int f=1; ; ++f) {
    ll ax=x, ay=y;
    string ret;
    for (int v=f; v>=1; --v) {
      ll dy[]={v,0,-v,0};
      ll dx[]={0,-v,0,v};
      string name="NWSE";
      ll msum=1LL<<60;
      int pp = -1;
      REP(r, 4) {
        ll tmp = abs(ax+dx[r])+abs(ay+dy[r]);
        if (msum > tmp) {
          msum = tmp;
          pp = r;
        }
      }

      ax = ax+dx[pp];
      ay = ay+dy[pp];
      ret += name[(pp+2)%4];
    }

    if (ax==0 && ay==0) {
      reverse(ret.begin(), ret.end());
      cout << ret << endl;
      // let us verify

      ax=0, ay=0;
      REP(j, f) {
        if (ret[j]=='N') ay+=j+1;
        if (ret[j]=='S') ay-=j+1;
        if (ret[j]=='E') ax+=j+1;
        if (ret[j]=='W') ax-=j+1;
      }
      assert(ax==x && ay==y);

      break;
    }
  }
}
