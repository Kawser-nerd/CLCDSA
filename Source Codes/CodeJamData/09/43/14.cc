/* headers {{{1 */
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/* defines {{{1 */
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << "\n"
#define debugf(x...) fprintf(stderr, x)
#define mp make_pair
#define pb push_back
#define A first
#define B second
#define X real()
#define Y imag()
#define sz(v) ((int)(v).size())
#define foreach(i, v) for (typeof(v.begin()) i = v.begin(); i != v.end(); ++i)

typedef long long ll;
const int inf = 1 << 29; const ll llinf = (ll)inf * (ll)inf;

/* funcs {{{1 */
template<class T> inline T gcd(T a, T b) { return (b == 0) ? a : gcd(b, a % b); }
template<class T> inline T cross(complex<T> a, complex<T> b) { return a.X * b.Y - b.X * a.Y; }
template<class T> inline int cross_sign(complex<T> a, complex<T> b) { 
  double t = (double)a.X * b.Y - (double)b.X * a.Y; 
  return (abs(t) < 1e-9) ? 0 : (t > 0); 
}
template<class T1, class T2> struct conv_impl { inline static T1 conv(T2 x) { stringstream ss; ss << x; T1 y; ss >> y; return y; } };
template<class T2> struct conv_impl<string, T2> { inline static string conv(T2 x) { stringstream ss; ss << x; return ss.str(); } };
template<class T1, class T2> inline T1 conv(T2 x) { return conv_impl<T1, T2>::conv(x); }
template<class T> inline vector<T> split(string x, string y=" \n\t") { 
  vector<T> r; 
  for (int i = 0; i <= sz(x); ) { 
    int j = x.find_first_of(y, i); 
    if (j < 0) j = sz(x); 
    r.pb(conv<T>(x.substr(i, j - i))); 
    i = j + 1;
  }
  return r; 
}
template<class T> inline vector<T> tokenize(string x, string y=" \n\t") { 
  vector<T> r; 
  for (int i = x.find_first_not_of(y); 0 <= i && i <= sz(x); ) { 
    int j = x.find_first_of(y, i); 
    if (j < 0) j = sz(x); 
    r.pb(conv<T>(x.substr(i, j - i))); 
    i = x.find_first_not_of(y, j);
  }
  return r; 
}
/* end }}}1 */

template<class T, T Tinf> 
struct flow_graph_t {
  int n, m, ne;
  int *first, *start, *dist;
  int *to, *next; T *cap;
  int *q, qs, qe;
  int source, sink;

  inline flow_graph_t(int n_, int m_) {
    n = n_, m = m_ * 2;

    first = new int[n], start = new int[n], dist = new int[n], q = new int[n];
    to = new int[m], next = new int[m], cap = new T[m];

    fill(first, first + n, -1);
    ne = 0;
  }

  inline ~flow_graph_t() {
    delete[] first, delete[] start, delete[] dist, delete[] q;
    delete[] to, delete[] next, delete[] cap;
  }

  inline void edge(int x, int y, T xy, T yx=0) {
    to[ne] = y, next[ne] = first[x], cap[ne] = xy, first[x] = ne++;
    to[ne] = x, next[ne] = first[y], cap[ne] = yx, first[y] = ne++;
  }

  inline bool bfs() {
    fill(dist, dist + n, -1);
    dist[source] = 0, q[qs = 0] = 0, qe = 1;
    while (qs < qe) {
      start[q[qs]] = first[q[qs]];
      if (q[qs] == sink) return true;
      for (int e = first[q[qs]]; e != -1; e = next[e])
      if (dist[to[e]] == -1 && cap[e] > 0) {
        dist[to[e]] = dist[q[qs]] + 1;
        q[qe++] = to[e];
      }
      ++qs;
    }
    return false;
  }

  T dfs(int x, T f) {
    if (x == source || f == 0) return f;
    T r = 0;
    for (int &e = start[x]; e != -1; e = next[e])
    if (cap[e ^ 1] > 0 && dist[x] - 1 == dist[to[e]]) {
      T c = dfs(to[e], min(f, cap[e ^ 1]));
      f -= c, r += c, cap[e] += c, cap[e ^ 1] -= c;
      if (f == 0) break;
    }
    return r;
  }

  inline T flow(int source_, int sink_) {
    source = source_, sink = sink_;
    T ret = 0;
    while (bfs()) ret += dfs(sink, Tinf);
    return ret;
  }
};

const int MAXN = 100;

void solve_case() {
  int n, m;
  cin >> n >> m;
  int a[MAXN][MAXN];
  for (int i = 0; i < n; ++i)
  for (int j = 0; j < m; ++j) cin >> a[i][j];

  flow_graph_t<int, inf> graph(2 + 2 * n, 2 * n + n * n);

  for (int i = 0; i < n; ++i) graph.edge(0, 2 + i, 1, 0);
  for (int i = 0; i < n; ++i) graph.edge(2 + n + i, 1, 1, 0);

  for (int i = 0; i < n; ++i)
  for (int j = 0; j < n; ++j) {
    bool ok = true;
    for (int k = 0; k < m; ++k) ok = ok && (a[i][k] < a[j][k]);
    if (ok) graph.edge(2 + i, 2 + n + j, 1, 0);
  }

  cout << n - graph.flow(0, 1) << '\n';
}

void base_init() {
}

const bool newline_after_case = false;

/* main {{{1 */
int main() {
  base_init(); 
  int t; 
  scanf("%d", &t);
  for (int i = 1; i <= t; ++i) {
    printf("Case #%d:%s", i, newline_after_case ? "\n" : " "); 
    solve_case();
  }
  return 0;
}
/* end }}}1 */


