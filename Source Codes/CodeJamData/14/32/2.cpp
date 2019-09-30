#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
//#define TASKNAME ""

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define sz(x) ((int)(x).size())

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<pii> vpii;

//const int inf = 1e9;
const double eps = 1e-7;
//const int INF = inf;
const double EPS = eps;

#ifdef DEBUG
struct __timestamper {
	~__timestamper(){
		TIMESTAMP(end);
	}
} __Timestamper;
#else
struct __timestamper {};
#endif

/*Template end*/

const int MOD = 1e9 + 7;
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }

bool _solve(const vector<string> &all) {
  int ck = 1;

  int gcnt = 0;
  vi nes(sz(all), -1), prs(sz(all), -1);
  vb alive(sz(all), true);

  for (char c = 'a'; c <= 'z'; c++) {
    vi carts[4] = {};
    int scnt = 0;

    for (int id = 0; id < sz(all); id++) {
      const string &s = all[id];
      int l = find(s.begin(), s.end(), c) - s.begin();
      if (l >= sz(s)) continue;

      int r = l;
      while (r < sz(s) && s[r] == s[l]) r++;
      if (find(s.begin() + r, s.end(), c) != s.end()) return false;

      int msk = 0;
      if (l == 0) msk |= 1;
      if (r == sz(s)) msk |= 2;
      carts[msk].pb(id);
      scnt++;
    }
    if (!scnt) continue;

    if (!carts[0].empty()) {
      if (scnt > 1) return false;
      continue;
    }
    if (sz(carts[1]) > 1) return false;
    if (sz(carts[2]) > 1) return false;

    for (int i = 1; i <= sz(carts[3]); i++)
      ck = mmul(ck, i);
    
    if (!carts[1].empty() && !carts[2].empty()) {
      int a = carts[2][0];
      int b = carts[1][0];
      assert(nes[a] < 0);
      assert(prs[b] < 0);
      nes[a] = b;
      prs[b] = a;
    }

    for (int x : carts[3]) {
      assert(alive[x]);
      alive[x] = false;
    }
    if (carts[1].empty() && carts[2].empty()) {
      gcnt++;
    }
  }
/*  eprintf("gcnt=%d\n", gcnt);
  for (int i = 0; i < sz(all); i++)
    if (alive[i])
      eprintf("%d .. %d .. %d\n", prs[i], i, nes[i]);*/

  for (int i = 0; i < sz(all); i++)
    if (prs[i] < 0 && alive[i]) {
      gcnt++;
      for (int x = i; x >= 0; x = nes[x]) {
        if (!alive[x]) return false; 
        alive[x] = false;
      }
    }
  for (int i = 0; i < sz(all); i++)
    if (alive[i]) return false;

  assert(gcnt >= 1);
//  eprintf("gcnt=%d, ck=%d\n", gcnt, ck);
  for (int i = 1; i <= gcnt; i++)
    ck = mmul(ck, i);
  printf("%d\n", ck);
  return true;
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<string> data(n);
  for (int i = 0; i < n; i++) {
    static char buf[200];
    scanf("%s", buf);
    data[i] = buf;
  }
  if (!_solve(data)) {
    printf("0\n");
  }
}

bool endsWith(string a, string b) {
  return a.length() >= b.length() && string(a, a.length() - b.length()) == b;
}

int main(int argc, char *argv[]) {
  {
    string fn = "";
    if (argc >= 2) fn = argv[1];
    if (endsWith(fn, ".in")) fn = string(fn, 0, fn.length() - 3);
    freopen((fn + ".in").c_str(), "r", stdin);
    freopen((fn + ".out").c_str(), "w", stdout);
  }

  int TC;
  assert(scanf("%d", &TC) >= 1);
  for (int TN = 1; TN <= TC; TN++) {
    eprintf("Case #%d:\n", TN);
    printf("Case #%d: ", TN);
    try {
      solve();
    } catch (...) {
      eprintf("Caught exception at test case #%d\n", TN);
      return 1;
    }
  }
  return 0;
}
