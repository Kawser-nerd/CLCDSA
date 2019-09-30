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

const int MAX_N = 1000; 

int n;
int x[MAX_N], y[MAX_N], c[MAX_N];

int main() {
  cin >> n;
  rep(i,n) {
    cin >> x[i] >> y[i] >> c[i];
  }

  double lb = -1e5-1, ub = 1e5+1, mid;
  double ans = 0.0;
  for (int i = 0; i < 50; ++i) {
    mid = (lb+ub)/2;
    double m = 0;
    for (int j = 0; j < n; ++j) {
    double r = (x[j]-mid > 0 ? x[j]-mid : mid-x[j]);
     m = max((double)c[j]*r, m);
    }
    double m2 = 0;
    for (int j = 0; j < n; ++j) {
    double r = (x[j]-(mid+1e-7) > 0 ? x[j]-(mid+1e-7) : (mid+1e-7)-x[j]);
     m2 = max((double)c[j]*r, m2);
    }
    if (m2-m > 0) {
      ub = mid;
    } else {
      lb = mid;
    }
    ans = m;
  }

  double ans2 = 0.0;
  lb = -1e5-1, ub = 1e5+1;
  for (int i = 0; i < 50; ++i) {
    mid = (lb+ub)/2;
    double m = 0;
    for (int j = 0; j < n; ++j) {
    double r = (y[j]-mid > 0 ? y[j]-mid : mid-y[j]);
     m = max((double)c[j]*r, m);
    }
    double m2 = 0;
    for (int j = 0; j < n; ++j) {
    double r = (y[j]-(mid+1e-7) > 0 ? y[j]-(mid+1e-7) : (mid+1e-7)-y[j]);
     m2 = max((double)c[j]*r, m2);
    }
    if (m2-m > 0) {
      ub = mid;
    } else {
      lb = mid;
    }
    ans2 = m;
  }

  printf("%f\n", max(ans, ans2));

  return 0;
}