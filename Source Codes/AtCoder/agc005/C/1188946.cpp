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

int main() {
  int n;
  scanf("%d", &n);
  vi a(n);
  vi num_of_d(n-1, 0);
  rep (i, n) {
    scanf("%d", &a[i]);
    num_of_d[a[i]] += 1;
  }
  sort(all(a));
  int max_d = a.back();
  int min_d = (max_d + 1) / 2;
  rep (i, min_d) {
    if (num_of_d[i] != 0) {
      printf("Impossible\n");
      return 0;
    }
  }
  if ((max_d&1) == 0) {
    if (num_of_d[min_d] != 1) {
      printf("Impossible\n");
      return 0;
    }
  } else {
    if (num_of_d[min_d] != 2) {
      printf("Impossible\n");
      return 0;
    }
  }
  FOR (i, min_d + 1, max_d + 1) {
    if (num_of_d[i] < 2) {
      printf("Impossible\n");
      return 0;
    }
  }
  printf("Possible\n");

  return 0;
}