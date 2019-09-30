#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define pb push_back
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<i_i, int> p_i;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
template<class T> using vv=vector<vector< T > >;

int main() {
  ll l, x, y, s, d;
  cin >> l >> x >> y >> s >> d;
  if (d >= s) {
    d -= s;
  } else {
    d += (l - s);
  }
  double right, left;
  right = ((double)d) / (x+y);
  left = 9999999999.9;
  if (-x+y > 0) {
    left = ((double)(l-d)) / (-x+y);
  }
  printf("%f\n", min(right, left));

  return 0;
}