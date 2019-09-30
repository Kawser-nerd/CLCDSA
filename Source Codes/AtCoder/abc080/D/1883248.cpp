#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<sstream>
#include<climits>
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 100000, MAX_C = 30;
int N, C;
int s[MAX_N], t[MAX_N], c[MAX_N];
vector<pii> cs[MAX_C+1];
int dp[MAX_N+1];

int main() {
  cin >> N >> C;
  rep(i,N) cin >> s[i] >> t[i] >> c[i];

  rep(i,N) {
    cs[c[i]].push_back(pii(s[i],t[i]));
  }
  rep(i,C+1) {
    sort(all(cs[i]));
  }

  for (int i = 1; i <= C; ++i) {
    for (int j = 0; j < (int)cs[i].size(); ++j) {
      if (j == 0 || cs[i][j-1].sc < cs[i][j].fi) {
        for (int k = cs[i][j].fi; k <= cs[i][j].sc; ++k) ++dp[k];
      } else {
        for (int k = cs[i][j].fi+1; k <= cs[i][j].sc; ++k) ++dp[k];
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= 1e5; ++i) ans = max(ans, dp[i]);

  cout << ans << endl;

  return 0;
}