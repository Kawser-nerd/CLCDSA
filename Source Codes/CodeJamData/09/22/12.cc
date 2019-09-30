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
#define iterate(i, a, b) for (typeof(a) i = a; i != b; i++)
#define sz(v) ((int)v.size())
#define foreach(i, v) iterate(i, v.begin(), v.end())

typedef long long ll;
const int inf = 1 << 29; const ll llinf = (ll)inf * (ll)inf;

/* funcs {{{1 */
template<class T> inline T gcd(T a, T b) { return (b == 0) ? a : gcd(b, a % b); }
template<class T> inline T cross(complex<T> a, complex<T> b) { return a.X * b.Y - b.X * a.Y; }
template<class T> inline int cross_sign(complex<T> a, complex<T> b)
{ double t = (double)a.X * b.Y - (double)b.X * a.Y; return (abs(t) < 1e-9) ? 0 : (t > 0); }
template<class T1, class T2> inline T1 conv(T2 x) { stringstream ss; ss << x; T1 y; ss >> y; return y; }
template<class T> inline vector<T> tokenize(string x, string y) 
{ vector<T> r; for (int i = 0; i <= sz(x); ) { int j = x.find_first_of(y, i); if (j < 0) j = sz(x); r.pb(conv<T>(x.substr(i, j - i))); i = j + 1; } return r; }

/* end }}}1 */

void solve_case() {
  string s;
  cin >> s;
  s = "0" + s;
  next_permutation(s.begin(), s.end());
  if (s[0] == '0') s = s.substr(1);
  cout << s << "\n";
}

void base_init() {
}

/* main {{{1 */
int main() {
  base_init(); int t; scanf("%d", &t); for (int i = 1; i <= t; ++i) printf("Case #%d: ", i), solve_case(); return 0;
}
/* }}}1 */


