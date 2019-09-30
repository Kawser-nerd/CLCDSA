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
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_N = 50;
const ll INF = 1e18;
int N;
ll a[MAX_N];

int main() {
  cin >> N;
  rep(i, N) cin >> a[i];

  ll lb = -1, ub = INF, mid;
  while (ub-lb > 1) {
    mid = (ub+lb)/2;
    ll k = 0;
    for (int i = 0; i < N; ++i) {
      k += (a[i]+mid+1)/(N+1);
    }
    if (k <= mid) ub = mid;
    else lb = mid;
  }

  ll ans = ub;
  for (ll i = lb; i >= lb-1e5 && i >= 0; --i) {
    ll k = 0;
    for (int j = 0; j < N; ++j) {
      k += (a[j]+i+1)/(N+1);
    }
    if (k <= i) ans = i;
  }

  cout << ans << endl;

  return 0;
}