#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<bool> db;
template<class T> using vv=vector<vector< T > >;

int n = 100;
int swapped;

void print_ans(vvi & ans) {
  printf("100 100\n");
  rep (i, n) {
    rep (j, n) {
      char c;
      if ((ans[i][j] + swapped) % 2 == 0) {
        c = '.';
      } else {
        c = '#';
      }
      printf("%c", c);
    }
    printf("\n");
  }
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  a -= 1; b -= 1;
  vvi ans(n, vi(n, -1));
  swapped = 0;
  FOR (i, 0, n/2) {
    rep (j, n) {
      ans[i][j] = 1;
    }
  }
  FOR (i, n/2, n) {
    rep (j, n) {
      ans[i][j] = 0;
    }
  }
  for (int i = 0; i < n/2; i += 2) {
    for (int j = 0; j < n; j += 2) {
      if (a == 0) { break; }
      if (a > 0) {
        ans[i][j] = 0;
        a -= 1;
      }
    }
  }
  for (int i = n-1; i >= n/2; i -= 2) {
    for (int j = 0; j < n; j += 2) {
      if (b == 0) { break; }
      if (b > 0) {
        ans[i][j] = 1;
        b -= 1;
      }
    }
  }

  print_ans(ans);

  return 0;
}