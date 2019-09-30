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

const int MAX = 200;
int h, w;
int c[10][10];
int a[MAX][MAX];

int main() {
  cin >> h >> w;
  rep(i,10) {
    rep(j,10) {
      cin >> c[i][j];
    }
  }
  rep(i,h) {
    rep(j,w) {
      cin >> a[i][j];
    }
  }

  for (int k = 0; k < 10; ++k) {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
      }
    }
  }

  ll ans = 0;
  rep(i,h) {
    rep(j,w) {
      if (a[i][j] != -1) ans += c[a[i][j]][1];
    }
  }

  cout << ans << endl;

  return 0;
}