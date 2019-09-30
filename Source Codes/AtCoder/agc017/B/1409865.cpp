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

void no() {
  printf("NO\n");
  exit(0);
}

void yes() {
  printf("YES\n");
  exit(0);
}

int main() {
  int n, a, b;
  ll c, d;
  scanf("%d%d%d %lld %lld", &n, &a, &b, &c, &d);
  int diff = abs(a - b);
  ll n1 = n - 1;
  if (n1 * d < diff) {
    no();
  }
  if (n1 * c <= diff) {
    yes();
  }

  FOR (i, 1, n-1) {
    ll left_min = c * i;
    ll left_max = d * i;
    ll right_min = c * (n1 - i);
    ll right_max = d * (n1 - i);
    if (diff + left_max >= right_min && right_max >= diff + left_min) {
      yes();
    }
  }
  no();

  return 0;
}