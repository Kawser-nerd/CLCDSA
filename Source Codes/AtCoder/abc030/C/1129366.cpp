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
#include <tuple>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
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
  int n, m;
  scanf("%d %d", &n, &m);
  int x, y;
  scanf("%d %d", &x, &y);
  vi a(n), b(m);
  rep (i, n) {
    scanf("%d", &a[i]);
  }
  rep (i, m) {
    scanf("%d", &b[i]);
  }
  int current_time = 0;
  int cnt = 0;
  auto lb = lower_bound(all(a), current_time);
  while (true) {
    lb = lower_bound(all(a), current_time);
    if (lb == end(a)) {
      break;
    }
    current_time = *lb;
    current_time += x;
    lb = lower_bound(all(b), current_time);
    if (lb == end(b)) {
      break;
    }
    current_time = *lb;
    current_time += y;
    cnt += 1;
  }
  printf("%d\n", cnt);

  return 0;
}