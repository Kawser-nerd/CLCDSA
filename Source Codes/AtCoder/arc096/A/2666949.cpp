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
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  if (x > y) {
    swap(a, b);
    swap(x, y);
  }
  if (a + b <= 2 * c) {
    printf("%d\n", a * x + b * y);
    return 0;
  }

  int numab = min(x, y) * 2;
  x -= numab / 2;
  y -= numab / 2;

  if (b <= 2 * c) {
    printf("%d\n", c * numab + b * y);
  } else {
    int addab = y * 2;
    printf("%d\n", c * (numab + addab));
  }

  return 0;
}