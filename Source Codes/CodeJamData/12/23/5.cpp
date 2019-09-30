#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int random(int l, int r) {
  int v = (rand() << 16) | rand();
  v %= r - l + 1;
  return l + abs(v);
}

int n;
vll as;

void solve() {
  scanf("%d", &n);
  as = vll(n);
  for (int i = 0; i < n; i++)
    scanf("%I64d", &as[i]);

  map<ll, vll> was;
  for (int step = 0;; step++) {
    if (step % 100000 == 0)
    eprintf("%d\n", step);
    vll cur;
    int cnt = random(1, 10);
    for (int i = 0; i < cnt; i++) {
      cur.pb(as[random(0, n - 1)]);
    }
    sort(cur.begin(), cur.end());
    cur.erase(unique(cur.begin(), cur.end()), cur.end());

    ll sum = 0;
    for (int i = 0; i < sz(cur); i++) sum += cur[i];
    if (was.count(sum)) {
      vll v2 = was[sum];
      if (v2 != cur) {
        set<ll> was1, was2;
        for (int i = 0; i < sz(cur); i++) was1.insert(cur[i]);
        for (int i = 0; i < sz(v2); i++) was2.insert(v2[i]);

        ll res = 0;
        for (int i = 0; i < sz(cur); i++) if (!was2.count(cur[i])) printf("%I64d ", cur[i]), res += cur[i]; printf("\n");
        for (int i = 0; i < sz(v2); i++) if (!was1.count(v2[i])) printf("%I64d ", v2[i]), res -= v2[i]; printf("\n");
        assert(res == 0);
        return;
      }
    }
    was.insert(mp(sum, cur));
  }
}

bool endsWith(string a, string b) {
  return a.length() >= b.length() && string(a, a.length() - b.length()) == b;
}

int main(int argc, char *argv[]) {
  {
    string fn = "std";
    if (argc >= 2) fn = argv[1];
    if (endsWith(fn, ".in")) fn = string(fn, 0, fn.length() - 3);
    freopen((fn + ".in").c_str(), "r", stdin);
    freopen((fn + ".out").c_str(), "w", stdout);
  }

  int TC;
  assert(scanf("%d", &TC) >= 1);
  for (int TN = 1; TN <= TC; TN++) {
    eprintf("Case #%d:\n", TN);
    printf("Case #%d:\n", TN);
    try {
      solve();
    } catch (...) {
      eprintf("Catched exception at test case #%d\n", TN);
      return 1;
    }
  }
  return 0;
}
