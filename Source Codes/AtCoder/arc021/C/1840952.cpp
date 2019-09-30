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

const int MAX_N = 100000;

int N, K;
int a[MAX_N], d[MAX_N];

int main() {
  cin >> K >> N;
  rep(i,N) cin >> a[i] >> d[i];

  ll lb = 0, ub = 1e12, mid, count;
  while (ub-lb > 1) {
    count = 0;
    mid = (lb+ub)/2;
    rep(i, N) {
      if (mid < a[i]) continue;
      ll t = (mid-a[i])/d[i] + 1;
      count += t;
    }
    if (count >= K) ub = mid;
    else lb = mid;
  }

  ll ans = 0;
  count = 0;

  rep(i, N) {
    if (ub < a[i]) continue;
    ll t = (ub-a[i])/d[i] + 1;
    count += t;
    ans += a[i]*t + (t*(t-1))/2*d[i];
  }

  ans -= (count-K)*ub;

  cout << ans << endl;

  return 0;
}