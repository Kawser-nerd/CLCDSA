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
  rep (i, n) {
    scanf("%d", &a[i]);
  }

  vi ind;
  if (n % 2 == 0) {
    for (int i = n; i > 1; i -= 2) {
      ind.push_back(i);
    }
    for (int i = 1; i < n; i += 2) {
      ind.push_back(i);
    }
  } else {
    for (int i = n; i >= 1; i -= 2) {
      ind.push_back(i);
    }
    for (int i = 2; i < n; i += 2) {
      ind.push_back(i);
    }
  }
  vi b;
  rep (i, n) {
    b.push_back(a[ind[i] - 1]);
  }
  rep (i, n) {
    printf("%d ", b[i]);
  }
  printf("\n");

  return 0;
}