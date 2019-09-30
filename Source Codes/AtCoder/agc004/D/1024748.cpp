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
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
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
// cout pair
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {
  s << p.first << " " << p.second << "\n"; return s;
}

// cout vector<pair>
template<typename T1, typename T2> ostream& operator<<(ostream& s, const vector<pair<T1, T2> >& vp) {
  int len = vp.size(); s << "\n";
  for (int i = 0; i < len; ++i) { s << vp[i]; }
    s << "\n"; return s;
}

// cout vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size(); s << "\n";
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  s << "\n"; return s;
}

// cout deque
template<typename T> ostream& operator<<(ostream& s, const deque<T>& v) {
  int len = v.size(); s << "\n";
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  s << "\n"; return s;
}

// cout 2-dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) { s << vv[i]; }
  return s;
}

// cout 2-dimentional deque
template<typename T> ostream& operator<<(ostream& s, const deque< deque<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) { s << vv[i]; }
  return s;
}

int n, k;
vector<vector<int> > child;
int ans;
vi a;

int solve(int x) {
  int len = child[x].size();
  if (len == 0) {
    return 0;
  }
  int ret = -5;
  rep (i, len) {
    int s = solve(child[x][i]);
    ret = max(ret, s);
  }
  ret += 1;
  if (x != 0 && ret == k-1 && a[x] != 0) {
    ans += 1;
    ret = -1;
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &k);
  a.resize(n);
  rep (i, n) {
    scanf("%d", &a[i]);
    a[i] -= 1;
  }
  ans = 0;

  if (k == 1) {
    rep (i, n) {
      if (a[i] != 0) {
        ans += 1;
      }
    }
    printf("%d\n", ans);
    return 0;
  }

  if (a[0] != 0) {
    ans += 1;
    a[0] = 0;
  }
  child.resize(n);
  FOR (i, 1, n) {
    child[a[i]].pb(i);
  }

  solve(0);
  printf("%d\n", ans);

  return 0;
}