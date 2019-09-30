#define NDEBUG
#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <tuple>
#include <utility>
using namespace std;

template <typename T> inline T set_bit(const T &x, int index) {
  return x | ((T)1 << index);
}
template<typename T, typename U> inline void makemin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}
template <typename T> inline T kill_bit(const T &x, int index) {
  return x & ~((T)1 << index);
}
template<typename Set, typename Element> inline bool inset( const Set &S, const Element &E ) { return S.find(E) != S.end(); }
template <typename T> inline int get_bit(const T &x, int index) {
  return int((x >> index) & 1);
}
#define ZERO(v) memset((v), 0, sizeof (v))

const int MAXN = 15;
int n;
pair<char, int> events[MAXN];

const int INF = INT_MAX/2;
bool been[MAXN][1<<MAXN];
int memo[MAXN][1<<MAXN];

int calc(int pos, int mask) {
  if (pos == n) {
    return __builtin_popcount(mask);
  }

  if (been[pos][mask]) {
    return memo[pos][mask];
  }

  int ret = INF;
  char type;
  int id;
  tie(type, id) = events[pos];
  if (type == 'L') {
    int a = id == -1 ? 0 : id;
    int b = id == -1 ? n-1 : id;
    for (int i=a; i<=b; ++i) {
      if (get_bit(mask, i)) {
        makemin(ret, calc(pos+1, kill_bit(mask, i)));
      }
    }
  } else {
    int a = id == -1 ? 0 : id;
    int b = id == -1 ? n-1 : id;
    for (int i=a; i<=b; ++i) {
      if (!get_bit(mask, i)) {
        makemin(ret, calc(pos+1, set_bit(mask, i)));
      }
    }
  }
  been[pos][mask] = 1;
  return memo[pos][mask] = ret;
}

void solve() {
  cin >> n;

  map<int, int> idmap;
  int n_ids = 0;
  idmap[0] = -1;
  for (int i=0; i<n; ++i) {
    char ch; int id;
    cin >> ws >> ch >> id;
    if (!inset(idmap, id)) {
      idmap[id] = n_ids++;
    }
    id = idmap[id];
    events[i] = make_pair(ch, id);
  }
  // debug(idmap);

  ZERO(been);
  int ans = INF;
  for (int mask=0; mask<(1<<n); ++mask) {
    makemin(ans, calc(0, mask));
  }
  if (ans != INF) {
    printf("%d\n", ans);
  } else {
    puts("CRIME TIME");
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    printf("Case #%d: ", tt);
    solve();
    fflush(stdout);
  }
}
