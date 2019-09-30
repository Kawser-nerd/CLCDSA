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

const int MAXN = 60;

bool wall[MAXN][MAXN];

int h, w, f;

int mem[MAXN][MAXN][MAXN];

int fall(int r, int c) {
  int nr = r + 1;
  while (!wall[nr + 1][c]) ++nr;
  if (nr - r > f) return -1;
  return nr;
}

int solve(int r, int c, int extra) {
  if (r == h) return 0;

  int &ret = mem[r][c][extra];
  if (ret != -1) return ret;
  ret = inf;

  int left = c, right = c;

  if (extra < c) left = extra;
  if (extra > c) right = extra;

  while (wall[r][right + 1] == false) ++right;
  while (wall[r][left - 1] == false) --left;

  int nleft = c;
  while (nleft - 1 >= left && wall[r + 1][nleft - 1]) --nleft;
  int nright = c;
  while (nright + 1 <= right && wall[r + 1][nright + 1]) ++nright;

  int x = fall(r, nleft - 1);
  if (left < nleft && x != -1) ret = min(ret, solve(x, nleft - 1, nleft - 1));
  x = fall(r, nright + 1);
  if (nright < right && x != -1) ret = min(ret, solve(x, nright + 1, nright + 1));

  for (int i = nleft; i <= nright; ++i) {
    x = fall(r, i);
    if (x == -1) continue;

    if (x > r + 1) {
      if (nleft < i || i < nright) ret = min(ret, solve(x, i, i) + 1);
      continue;
    }

    if (i > nleft) {
      int c = 1;
      for (int j = i; j <= nright; ++j) {
        ret = min(ret, solve(x, i, j) + c);
        ++c;
      }
    }

    if (i < nright) {
      int c = 1;
      for (int j = i; j >= nleft; --j) {
        ret = min(ret, solve(x, i, j) + c);
        ++c;
      }
    }
  }

  return ret;
}


void solve_case() {
  memset(wall, true, sizeof(wall));

  cin >> h >> w >> f;

  for (int r = 1; r <= h; ++r) {
    string s;
    cin >> s;
    for (int c = 1; c <= w; ++c) wall[r][c] = (s[c - 1] == '#');
  }

  int r = (wall[2][1] ? 1 : fall(1, 1));
  if (wall[1][1] || r == -1) {
    cout << "No\n";
    return;
  }

  memset(mem, 255, sizeof(mem));

  int ans = solve(r, 1, 1);
  if (ans == inf) cout << "No\n";
  else cout << "Yes " << ans << "\n";
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


