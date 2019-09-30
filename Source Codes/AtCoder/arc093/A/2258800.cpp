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

int abs (int x) {
  if (x < 0) {
    x *= (-1);
  }
  return x;
}

int main() {
  int n;
  scanf("%d", &n);
  vi a(n+2, 0);
  FOR (i, 1, n+1) {
    scanf("%d", &a[i]);
  }
  int sum = 0;
  rep (i, n+1) {
    sum += (abs(a[i+1] - a[i]));
  }
  FOR (i, 1, n+1) {
    int orig = 0;
    orig += abs(a[i] - a[i-1]);
    orig += abs(a[i+1] - a[i]);
    int chg = abs(a[i+1] - a[i-1]);
    printf("%d\n", sum - orig + chg);
  }
  return 0;
}