/*-----------TEMPLATE---------------*/
//#pragma comment(linker, "/STACK:16777216")

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define eprintf(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#define forab(i, a, b) for (int i = (int)(a); i < ((int)(b)); ++i)
#define forit(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define forn(i, n) for (int i = 0; i < ((int)(n)); ++i)
#define forabok(i, a, b, ok) for (int i = (int)(a); i < ((int)(b)) && (ok); ++i)
#define foritok(it, v, ok) for (typeof((v).begin()) it = (v).begin(); it != (v).end() && (ok); ++it)
#define fornok(i, n, ok) for (int i = 0; i < ((int)(n)) && (ok); ++i)
#define mp make_pair
#define pb push_back
#define sz(a) ((int)((a).size()))
#define X first
#define Y second
#define ibits(x) __builtin_popcount(x)
#define lbits(x) __builtin_popcountll(x)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

/*-----------TEMPLATE---------------*/

vector<int> pnts;
vector<int> h;
vector<pair<int, int> > days;

const int inf = 1<<30;

int K;
vector<int> tree;
vector<int> vs;
void build_tree() {
  K = 1;
  while (K <= sz(pnts)) {
    K <<= 1;
  } 
  tree = vector<int>(2 * K, 0);
  vs = vector<int>(2 * K, 0);
}

void push(int t) {
  tree[t] = max(tree[t], vs[t]);
  if (t < K) {
    vs[2 * t] = max(vs[t], vs[2 * t]);
    vs[2 * t + 1] = max(vs[t], vs[2 * t + 1]);
  }
}

int get_min(int t, int l, int r, int L, int R) {
  push(t);
  if (l >= R || L >= r)
    return inf;
  if (l <= L && R <= r)
    return tree[t];

  int M = (L + R) / 2;
  return min(get_min(2 * t, l, r, L, M), get_min(2 * t + 1, l, r, M, R));
}

int get_min(int from, int to) {
  int p_f = lower_bound(pnts.begin(), pnts.end(), from) - pnts.begin();
  int p_t = upper_bound(pnts.begin(), pnts.end(), to) - pnts.begin();
  
  return get_min(1, p_f, p_t, 0, K);
}

int set_all(int t, int l, int r, int L, int R, int val) {
  push(t);
  if (l >= R || L >= r)
    return tree[t];

  if (l <= L && R <= r) {
    vs[t] = max(vs[t], val);
    push(t);
    return tree[t];
  }

  int M = (L + R) / 2;
  return tree[t] = min(set_all(2 * t, l, r, L, M, val), set_all(2 * t + 1, l, r, M, R, val));
}

void set_all(int from, int to, int new_h) {
  int p_f = lower_bound(pnts.begin(), pnts.end(), from) - pnts.begin();
  int p_t = upper_bound(pnts.begin(), pnts.end(), to) - pnts.begin();
  
  set_all(1, p_f, p_t, 0, K, new_h);
}

int stupid_get_min(int from, int to) { 
  int mn = inf;
  for(int i = 0; i < sz(pnts); i++) {
    if (pnts[i] >= from && pnts[i] <= to) {
      mn = min(mn, h[i]);
    }
  }
  return mn;
}

void stupid_set_all(int from, int to, int new_h) { 
  for(int i = 0; i < sz(pnts); i++) {
    if (pnts[i] >= from && pnts[i] <= to) {
      h[i] = max(h[i], new_h);
    }
  }
}

struct tribe {
  int d, n, w, e, s;
  int delta_d, delta_p, delta_s; 
  tribe(){}

  void read() {                                                                
    scanf("%d %d", &d, &n);
    scanf("%d %d %d", &w, &e, &s);
    scanf("%d", &delta_d);
    scanf("%d", &delta_p);
    scanf("%d", &delta_s);

    w *= 2;
    e *= 2;
    delta_p *= 2;
  }

  bool attack() {
//    eprintf("day = %d w = %d e = %d s = %d min = %d st_min = %d\n", 
//            d, w, e, s, get_min(w, e), stupid_get_min(w, e));
    
//    assert(get_min(w, e) == stupid_get_min(w, e)); //DEBUG
    return get_min(w, e) < s;
  }

  void finish() {
    d += delta_d;
    n--;
    w += delta_p;
    e += delta_p;
    s += delta_s;
  }

  void defend() {
//    stupid_set_all(w, e, s); //DEBUG

    set_all(w, e, s);
    finish();
  }
};

const int maxn = 2000;
tribe t[maxn];

void add_pnt(int p) {
  pnts.pb(p);
}

void add_pnt(const tribe& t) {
  int now_w = t.w, now_e = t.e;

  for(int i = 0; i < t.n; i++) {
    add_pnt(now_w);
    add_pnt(now_e);
    
    now_w += t.delta_p;
    now_e += t.delta_p;
  }
}

void add_days(const tribe& t, int num) {
  int now_d = t.d;
  for(int i = 0; i < t.n; i++) {
    days.pb(mp(now_d, num));
    now_d += t.delta_d;
  }
}

void solve() {
  int n;
  scanf("%d",&n);
  pnts.clear();
  days.clear();
  for(int i = 0; i < n; i++) {
    t[i].read();
    add_pnt(t[i]);
    add_days(t[i], i);
  }

  sort(all(pnts));
  for(int i = sz(pnts) - 1; i > 0; i--) {
    add_pnt((pnts[i] + pnts[i - 1]) / 2);
  } 
  sort(all(pnts));
  pnts.resize(unique(all(pnts)) - pnts.begin());
  sort(all(days));
  h = vector<int>(sz(pnts), 0);

  build_tree();

  int ans = 0;
  for(int i = 0; i < sz(days); ) {
    int j = i;
    while (j < sz(days) && days[i].first == days[j].first)
      j++;

    for(int k = i; k < j; k++) {
      if (t[days[k].second].attack()) {
        ans++;
      }
    }

    for(int k = i; k < j; k++) {
      t[days[k].second].defend();
    }

    i = j;
  }

  printf("%d\n", ans);
}

int main() 
{
  srand(time(NULL));
  #define TASK ""
  #ifdef HOME
  assert(freopen(TASK "in", "rt", stdin));
  assert(freopen(TASK "out", "wt", stdout));
  #endif

  int tests;
  scanf("%d",&tests);
  for(int test = 1; test <= tests; test++) {
    printf("Case #%d: ",test);
    solve();
  }
  return 0;
}