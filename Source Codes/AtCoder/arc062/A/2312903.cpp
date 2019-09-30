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

const int MAX_N = 1000;
int N;
int T[MAX_N], A[MAX_N];

int main() {
  cin >> N;
  rep(i,N) cin >> T[i] >> A[i];

  ll t = 1, a = 1;
  ll ans = 0;
  for (int i = 0; i < N; ++i) {
   ll k = max((t+(T[i]-1))/T[i], (a+(A[i]-1))/A[i]); 
   t = k*T[i]; a = k*A[i];
   ans = (T[i]+A[i])*k;
  }

  cout << ans << endl;

  return 0;
}