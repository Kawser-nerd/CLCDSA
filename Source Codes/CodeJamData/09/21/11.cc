/* headers {{{1 */
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <complex>
#include <iostream>
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
{ vector<T> r; for (int i = x.find_first_not_of(y); i >= 0 && i < sz(x); ) { int j = x.find_first_of(y, i); if (j < 0) j = sz(x); r.pb(conv<T>(x.substr(i, j - i))); i = x.find_first_not_of(y, j); } return r; }

/* end }}}1 */

int lines, animals;

string all;

int match[80 * 100 * 2], stack[80 * 100 * 2];

int find(int start, int end, char what) {
  for (int i = start; i < end; ++i) if (all[i] == what) return i;
  return end;
}

struct node_t {
  double prob;
  string feat;
  node_t *left, *right;
};

node_t* parse(int start) {
  int end = match[start];
  int left_start = find(start + 1, end, '(');

  node_t *node = new node_t();

  string x = all.substr(start + 1, left_start - (start + 1));
  vector<string> vx = tokenize<string>(x, " \n");

  node->prob = conv<double>(vx[0]);

  if (left_start != end) {
    node->feat = vx[1];
    node->left = parse(left_start);
    int right_start = find(match[left_start] + 1, end, '(');
    node->right = parse(right_start);
  } else {
    node->feat = "";
  }

  return node;
}

void ws(int x) { for (int i = 0; i < x; ++i) cerr << ' '; }

void print(node_t *node, int indent) {
  ws(indent);
  cerr << '(' << node->prob;

  if (node->feat == "") {
    cerr << ')' << '\n';
  } else {
    cerr << ' ' << node->feat << '\n';
    print(node->left, indent + 1);
    print(node->right, indent + 1);
    ws(indent);
    cerr << ')' << '\n';
  }
}

void solve_case() {
  cin >> lines;
  all = "";
  string t;
  getline(cin, t);
  for (int i = 0; i < lines; ++i) {
    string t;
    getline(cin, t);
    t += '\n';
    all += t;
  }

  int h = 0;
  for (int i = 0; i < sz(all); ++i) {
    if (all[i] == '(') stack[h++] = i;
    if (all[i] == ')') {
      int j = stack[--h];
      match[i] = j, match[j] = i;
    }
  }

  int start = find(0, sz(all), '(');
  node_t* root = parse(start);
  //print(root, 0);

  int q;
  cin >> q;
  getline(cin, t);
  for (int i = 0; i < q; ++i) {
    getline(cin, t);
    vector<string> v = tokenize<string>(t, " ");
    set<string> feats;
    for (int j = 2; j < sz(v); ++j) feats.insert(v[j]);
    node_t *c = root;
    double p = 1;
    while (true) {
      p *= c->prob;
      if (c->feat == "") break;
      if (feats.count(c->feat)) c = c->left; else c = c->right;
    }
    printf("%lf\n", p);
  }
}

void base_init() {
}

/* main {{{1 */
int main() {
  base_init(); int t; scanf("%d", &t); for (int i = 1; i <= t; ++i) printf("Case #%d:\n", i), solve_case(); return 0;
}
/* }}}1 */


