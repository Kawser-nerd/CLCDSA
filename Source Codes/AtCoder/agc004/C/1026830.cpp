#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
template<class T> using vv=vector<vector< T > >;

int main() {
  int h, w;
  scanf("%d %d", &h, &w);

  vector<vv<char> > result(2, vv<char>(h, vector<char>(w, '.')));
  rep (i, h) {
    result[0][i][0] = '#';
    result[1][i][w-1] = '#';
  }
  rep (i, h) {
    int r_b = i % 2;
    FOR (j, 1, w-1) {
      result[r_b][i][j] = '#';
    }
  }
  rep (i, h) {
    rep (j, w) {
      char tmp;
      scanf(" %c", &tmp);
      if (tmp == '#') {
        result[0][i][j] = result[1][i][j] = '#';
      }
    }
  }

  rep (i, h) {
    rep (j, w) {
      printf("%c", result[0][i][j]);
    }
    printf("\n");
  }
  printf("\n");
  rep (i, h) {
    rep (j, w) {
      printf("%c", result[1][i][j]);
    }
    printf("\n");
  }

  return 0;
}