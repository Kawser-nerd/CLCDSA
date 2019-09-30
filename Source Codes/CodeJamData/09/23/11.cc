/* headers {{{1 */
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <complex>
#include <iostream>
#include <map>
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

int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};

int n, q;
string m[20];

map<int, string> queries;
int rem;

map<int, string> best[20][20];

queue< pair< pair<int, int>, int > > cur, nex;

bool better(string a, string b) {
  if (a == "") return true;
  if (sz(a) < sz(b)) return false;
  if (sz(a) > sz(b)) return true;
  return a > b;
}

void add(int r, int c, int val, string path) {
  if (val < -100 || val > 400) return;
  if (queries.count(val) && better(queries[val], path)) {
    if (queries[val] == "") --rem;
    queries[val] = path;
  }

  if (best[r][c].count(val) == 0) {
    nex.push( mp( mp(r, c), val ) );
    best[r][c][val] = path;
  } else {
    if (better(best[r][c][val], path)) best[r][c][val] = path;
  }
}

bool ok(int r, int c) {
  return c >= 0 && c < n && r >= 0 && r < n;
}

void solve_case() {
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> m[i];

  string sq;
  getline(cin, sq);
  getline(cin, sq);
  vector<int> vq = tokenize<int>(sq, " ");

  queries.clear();
  foreach(i, vq) queries[*i] = "";
  rem = sz(queries);

  while (!cur.empty()) cur.pop();
  while (!nex.empty()) nex.pop();

  int flip = m[0][0] == '-' || m[0][0] == '+';

  for (int r = 0; r < n; r += 1)
  for (int c = (r % 2) ^ flip; c < n; c += 2) {
    best[r][c].clear();
    add(r, c, m[r][c] - '0', conv<string>(m[r][c]));
  }

  while (rem > 0) {
    while (!cur.empty()) {
      int r = cur.front().A.A, c = cur.front().A.B, val = cur.front().B;
      cur.pop();

      for (int d1 = 0; d1 < 4; ++d1) {
        int opr = r + dr[d1], opc = c + dc[d1];
        if (!ok(opr, opc)) continue;
        for (int d2 = 0; d2 < 4; ++d2) {
          int nr = opr + dr[d2], nc = opc + dc[d2];
          if (!ok(nr, nc)) continue;
          int nval = val;
          if (m[opr][opc] == '+') nval += m[nr][nc] - '0';
          else nval -= m[nr][nc] - '0';

          add(nr, nc, nval, best[r][c][val] + m[opr][opc] + m[nr][nc]);
        }
      }
    }
    swap(cur, nex);
  }

  foreach(i, vq) cout << queries[*i] << "\n";
}

void base_init() {
}

/* main {{{1 */
int main() {
  base_init(); int t; scanf("%d", &t); for (int i = 1; i <= t; ++i) printf("Case #%d:\n", i), solve_case(); return 0;
}
/* }}}1 */

