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
#define debug(x) cout<< #x <<": "<<x<<endl
#define debug2(x,y) cout<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<i_i, int> p_i;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
template<class T> using vv=vector<vector< T > >;

class VectorSort1 {
public:
  bool operator()(vector<ll> &left, vector<ll> &right) const {
    return left[2] < right[2];
  }
};
class VectorSort2 {
public:
  bool operator()(vector<ll> &left, vector<ll> &right) const {
    return left[0] < right[0];
  }
};
class VectorSort3 {
public:
  bool operator()(vector<ll> &left, vector<ll> &right) const {
    return left[1] < right[1]; // left[1], right[1] <= 0
  }
};

int main() {
  int n;
  cin >> n;
  vv<ll> a(n, vector<ll>(3));
  for (int i = 0; i < n; ++i) {
    cin >> a[i][0] >> a[i][1];
    a[i][1] *= (-1);
    a[i][2] = (a[i][0]+a[i][1]);
  }

  sort(begin(a), end(a), VectorSort1());
  vector<ll> sums;
  for (int i = 0; i < n; ++i) {
    sums.pb(a[i][2]);
  }
  sort(begin(a), begin(a) + distance(begin(sums), lower_bound(begin(sums), end(sums), 0)), VectorSort2());
  sort(begin(a) + distance(begin(sums), lower_bound(begin(sums), end(sums), 0)), end(a), VectorSort3());

  ll maxi = LLONG_MIN;
  ll current = 0;
  for (int i = 0; i < n; ++i) {
    current += a[i][0];
    maxi = max(maxi, current);
    current += a[i][1];
  }

  printf ("%lld\n", maxi);

  return 0;
}