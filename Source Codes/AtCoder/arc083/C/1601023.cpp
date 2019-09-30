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

// cout vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
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

struct Node {
  int color;
  int weight;
  vi acc;
  Node() {
    color = 0;
    weight = 0;
    acc = vi(2, 0);
  }
};

int INF = INT_MAX / 2;
vi X;

vi par;
vvi child;

vvi acc;

bool possible(int u) {
  if (child[u].size() == 0) {
    acc[u][0] = X[u];
    return true;
  }

  int all_sum = 0;
  map<int, bool> mp;
  mp[0] = true;

  for (int v : child[u]) {
    possible(v);
    all_sum += acc[v][0];
    all_sum += acc[v][1];
    map<int, bool> mp_;
    for (auto elm : mp) {
      if (elm.first > X[u]) { break; }
      mp_[elm.first + acc[v][0]] = true;
      mp_[elm.first + acc[v][1]] = true;
    }
    swap(mp, mp_);
  }

  auto itr = mp.upper_bound(X[u]);
  if (itr == begin(mp)) {
    printf("IMPOSSIBLE\n");
    exit(0);
  }

  itr --;
  acc[u][0] = all_sum - (*itr).first;
  acc[u][1] = X[u];

  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  par.assign(n, -1);
  child.resize(n);
  FOR (i, 1, n) {
    int p;
    scanf("%d", &p);
    p -= 1;
    par[i] = p;
    child[p].push_back(i);
  }

  X.resize(n);
  rep (i, n) {
    scanf("%d", &X[i]);
  }

  acc.assign(n, vi(2, 0));

  possible(0);
  printf("POSSIBLE\n");

  return 0;
}