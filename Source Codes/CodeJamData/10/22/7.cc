/* headers {{{1 */
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
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
#define len(v) ((int)(v).size())
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
  for (int i = 0; i <= len(x); ) { 
    int j = x.find_first_of(y, i); 
    if (j < 0) j = len(x); 
    r.pb(conv<T>(x.substr(i, j - i))); 
    i = j + 1;
  }
  return r; 
}
template<class T> inline vector<T> tokenize(string x, string y=" \n\t") { 
  vector<T> r; 
  for (int i = x.find_first_not_of(y); 0 <= i && i <= len(x); ) { 
    int j = x.find_first_of(y, i); 
    if (j < 0) j = len(x); 
    r.pb(conv<T>(x.substr(i, j - i))); 
    i = x.find_first_not_of(y, j);
  }
  return r; 
}
/* end }}}1 */

const int MAXN = 105;
int x[MAXN], v[MAXN];

void solve_case() {
  int n, k, b, t;
  scanf("%d%d%d%d", &n, &k, &b, &t);

  for (int i = 0; i < n; i++)
    scanf("%d", &x[i]);

  for (int i = 0; i < n; i++)
    scanf("%d", &v[i]);

  int ans = 0, to_skip = 0;
  for (int i = n - 1; i >= 0 && k > 0; i--) {
    if (x[i] + v[i] * t < b) {
      to_skip++;
    } else {
      ans += to_skip;
      k--;
    }
  }

  if (k > 0) {
    printf("IMPOSSIBLE\n");
  } else {
    printf("%d\n", ans);
  }
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


