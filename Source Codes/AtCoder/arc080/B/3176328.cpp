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

const int MAX_HW = 100;
int H, W, N;
int a[MAX_HW*MAX_HW];
int field[MAX_HW][MAX_HW];

int main() {
  cin >> H >> W >> N;
  rep(i,N) cin >> a[i];

  int count = 0;
  for (int i = 0; i < H; ++i) {
    if (i%2 == 0) {
      for (int j = 0; j < W; ++j) {
        field[i][j] = count+1;
        a[count]--;
        if (a[count] == 0) ++count;
      }
    } else {
      for (int j = W-1; j >= 0; --j) {
        field[i][j] = count+1;
        a[count]--;
        if (a[count] == 0) ++count;
      }
    }
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      printf("%d%c", field[i][j], j+1 == W ? '\n' : ' ');
    }
  }

  return 0;
}