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

int sum[1002000];
bool good[1002000];
void solve() {
  string s; int k;
  cin >> s >> k;
  int N = SZ(s);

  string vowel = "aiueo";

  sum[0] = 0;
  REP(i, N) {
    int p=1;
    REP(j, 5) if (vowel[j] == s[i]) { p=0; break; }
    sum[i+1] = sum[i]+p;
  }

  MEMSET(good, 0);
  for (int i=0; i+k<=N; ++i) {
    if (sum[i+k]-sum[i]==k) good[i]=1;
    // cout<<good[i]<<endl;
  }

  int prev = -1;
  ll res = 0;
  for (int i=0; i+k<=N; ++i) {
    if (good[i]) {
      res += (ll)(i-prev) * (N+1-(i+k));
      prev = i;
    }
  }

  cout << res << endl;


}
