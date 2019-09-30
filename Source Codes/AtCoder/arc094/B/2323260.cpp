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

int Q;

int main() {
  cin >> Q;

  while (Q--) {
    ll a, b;
    cin >> a >> b;

    if (a == b) {
      cout << 2*(a-1) << endl;
      continue;
    }

    ll lb = 0, ub = 1e9;
    while (ub-lb > 1) {
      ll mid = (ub+lb)/2;
      if (mid*mid >= a*b) ub = mid;
      else lb = mid;
    }
    if (lb*(lb+1) < a*b) {
      cout << 2*lb-1 << endl;
    } else {
      cout << 2*(lb-1) << endl;
    }
  }
}