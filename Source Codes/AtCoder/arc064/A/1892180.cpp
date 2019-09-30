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

const int MAX_N = 100000;
int N, x;
int a[MAX_N];

int main() {
  cin >> N >> x;
  rep(i, N) cin >> a[i];

  ll ans = 0;
  for (int i = 1; i < N; ++i) {
    if (a[i-1] + a[i] > x) {
      ans += (a[i-1]+a[i]) - x;
      a[i] -= min(a[i], (a[i-1]+a[i])-x);
    }
  }

  cout << ans << endl;

  return 0;
}