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

const int MAX_N = 100;
int n;
int a[MAX_N];

int main() {
  cin >> n;
  rep(i,n) cin >> a[i];

  ll ans = 0, sum = 0;
  rep(i,n) sum += a[i];
  ll x = sum / n;

  ll t = 0;
  rep(i,n) t += (x-a[i]) * (x-a[i]);
  ans = t;
  ++x; t = 0;
  rep(i,n) t += (x-a[i]) * (x-a[i]);
  ans = min(ans, t);

  cout << ans << endl;

  return 0;
}