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

ll n, s;

ll digitSum(ll n, ll b) {
  if (n == 0) return 0;
  return digitSum(n/b, b) + n%b;
}

int main() {
  cin >> n >> s;

  if (n == s) {
    cout << n+1 << endl;
    return 0;
  }

  ll r = sqrt(n);
  for (int b = 2; b <= r; ++b) {
    if (digitSum(n,b) == s) {
      cout << b << endl;
      return 0;
    }
  }

  vector<ll> bases;
  for (int p = 1; p <= r; ++p) {
    ll b = (n-s)/p + 1;
    if (b > 1) {
      if (digitSum(n, b) == s) {
        bases.push_back(b);
      }
    }
  }

  if (bases.size() == 0) {
    cout << -1 << endl;
  } else {
    sort(all(bases));
    cout << bases[0] << endl;
  }

  return 0;
}