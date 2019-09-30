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
#include<complex>
#include<sstream>
#include<climits>
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 1e5;
int N, H, W;
int a[MAX_N], b[MAX_N];
ll ans[10];

int main() {
  cin >> H >> W >> N;
  rep(i,N) cin >> a[i] >> b[i];

  map<pii, int> squres;
  for (int i = 0; i < N; ++i) {
    for (int x = 0; x > -3; --x) {
      for (int y = 0; y > -3; --y) {
        int px = a[i]+x, py = b[i]+y;
        if (0 < px && px < H-1 && 0 < py && py < W-1) squres[pii(px, py)]++;
      }
    }
  }

  for (map<pii, int>::iterator it = squres.begin(); it != squres.end(); ++it) {
    ans[it->second]++;
  }
  for (int i = 1; i < 10; ++i) ans[0] += ans[i];
  ans[0] = (ll)(H-2)*(ll)(W-2) - ans[0];

  for (int i = 0; i < 10; ++i) {
    printf("%lld\n", ans[i]);
  }

  return 0;
}