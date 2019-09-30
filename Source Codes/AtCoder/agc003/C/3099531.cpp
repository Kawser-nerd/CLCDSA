//#include <bits/stdc++.h>
// utility
#include <bitset>
#include <tuple>
#include <typeinfo>
// error handling
#include <cassert>
// string
#include <cctype>
#include <cstring>
#include <string>
// container
#include <array>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// algorithm
#include <algorithm>
// iterator
#include <iterator>
// math
#include <cmath>
#include <complex>
#include <numeric>
#include <random>
// i/o
#include <cstdio>
#include <iomanip>
#include <iostream>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
typedef __int128_t Int;
#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define loop(n) rep(loop, (0), (n))
#define all(c) begin(c), end(c)
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
#define fi first
#define se second
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T> void printvv(const vector<vector<T>> &v) {
  cerr << endl;
  rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
    if (typeid(v[i][j]) == typeid(INF) and v[i][j] == INF) {
      cerr << "INF";
    } else
      cerr << v[i][j];
    cerr << (j == v[i].size() - 1 ? '\n' : ' ');
  }
  cerr << endl;
}

#ifndef _DEBUG
#define printvv(...)
#endif
void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  int ans = 0;
  vector<int> w(v);
  sort(all(w));
  rep(i, 0, N) v[i] = lower_bound(all(w), v[i]) - w.begin();
  dump(v);
  rep(i, 0, N) { ans += i % 2 != v[i] % 2; }

  cout << ans/2 << endl;

  return 0;
} ./Main.cpp:53:40: warning: implicit conversion from 'long long' to 'const int' changes value from 4557430888798830399 to 1061109567 [-Wconstant-conversion]
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
                                       ^~~~~~~~~~~~~~~~~~~~
1 warning generated.