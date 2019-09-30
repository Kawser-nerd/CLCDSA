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

int n, m, p, q, r;
vector<vvi> yz;
int ans;

int calculate_max_value(vi& girl) {
  vi value_of_boy(m, 0);
  rep (i, p) {
    for (auto y_z : yz[girl[i]]) {
      value_of_boy[y_z[0]] += y_z[1];
    }
  }
  sort(all(value_of_boy), greater<int>());
  int ret = 0;
  rep (i, q) {
    ret += value_of_boy[i];
  }
  return ret;
}

template <class BidirectionalIterator>
bool next_combination(BidirectionalIterator first1, BidirectionalIterator last1, BidirectionalIterator first2, BidirectionalIterator last2) {
  if (first1 == last1 || first2 == last2) {
    return false;
  }
  BidirectionalIterator m1 = last1;
  BidirectionalIterator m2 = last2;
  --m2;
  while (--m1 != first1 && !(*m1 < *m2)) {}
  bool result = (m1 == first1 && !(*first1 < *m2));
  if (!result) {
    while (first2 != m2 && !(*m1 < *first2)) {
      ++first2;
    }
    first1 = m1;
    std::iter_swap(first1, first2);
    ++first1;
    ++first2;
  }
  if (first1 != last1 && first2 != last2) {
    m1 = last1; m2 = first2;
    while (m1 != first1 && m2 != last2) {
      std::iter_swap(--m1, m2);
      ++m2;
    }
    std::reverse(first1, m1);
    std::reverse(first1, last1);
    std::reverse(m2, last2);
    std::reverse(first2, last2);
  }
  return !result;
}

template <class BidirectionalIterator>
bool next_combination(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last) {
  return next_combination(first, middle, middle, last);
}

void solve() {
  ans = 0;
  vi girl(n);
  rep (i, n) {
    girl[i] = i;
  }
  do {
    ans = max(ans, calculate_max_value(girl));
  } while (next_combination(girl.begin(), girl.begin() + p, girl.end()));
}

int main() {
  scanf("%d%d%d%d%d", &n, &m, &p, &q, &r);
  yz.resize(n);
  rep (i, r) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    x -= 1;
    y -= 1;
    yz[x].push_back((vi){y, z});
  }

  solve();
  printf("%d\n", ans);

  return 0;
}