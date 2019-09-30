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

class UF {
private:
  vector<int> data; // parent or size
  vector<int> next;
  vector<int> last;
  void init(int n) {
    data.assign(n, -1);
    next.assign(n, -1);
    last.resize(n);
    for (int i = 0; i < n; ++i) {
      last[i] = i;
    }
  }

public:
  UF() {}
  UF(int n) {
    init(n);
  }
  int root(int x) {
    if (data[x] < 0) return x;
    return data[x] = root(data[x]);
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (data[x] > data[y]) swap(x, y); // data[x] and data[y] are negative.
    data[x] += data[y];
    data[y] = x;
    next[last[x]] = y;
    last[x] = last[y];
    return true;
  }
  int size(int x) {
    return -data[root(x)];
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  int get_next(int x) {
    return next[x];
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vi p(n);
  rep (i, n) {
    scanf("%d", &p[i]);
    p[i] -= 1;
  }
  UF uf(n);
  rep (i, m) {
    int x, y;
    scanf("%d %d", &x, &y);
    x -= 1; y -= 1;
    uf.unite(x, y);
  }

  vector<bool> done(n, false);
  int ans = 0;
  rep (i, n) {
    if (done[i]) {
      continue;
    }
    int r = uf.root(i);
    vi indices;
    vector<bool> exist_val(n, false);
    for (int j = r; j != (-1); j = uf.get_next(j)) {
      done[j] = true;
      indices.push_back(j);
      exist_val[p[j]] = true;
    }
    for (int ind : indices) {
      if (exist_val[ind]) {
        ans += 1;
      }
    }
  }
  printf("%d\n", ans);
    
  return 0;
}