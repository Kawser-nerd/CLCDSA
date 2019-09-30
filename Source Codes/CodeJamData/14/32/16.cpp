#include <cstdio>
#include <cassert>
#include <cstring>

#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x" = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int A = 26;
const int mod = 1000000007;

int g[A][A];
int succ[A];

bool lone_chars(string s) {
  static bool bio[A];
  REP(i, A) bio[i] = false;

  char last = '#';

  for (char c : s) {
    if (isalpha(c) && c != last) {
      int x = c -'a';

      if (bio[x]) return true;
      bio[x] = true;
    }

    last = c;
  }

  return false;
}

bool has_multiple() {
  REP(i, A) {
    int sum = 0;
    REP(j, A) if (i != j) sum += g[i][j];
    if (sum > 1) return true;
  }

  return false;
}

bool has_cycle() {
  static bool bio[A];

  REP(start, A) {
    REP(i, A) bio[i] = false;

    int x = start;
    while (x != -1) {
      if (bio[x]) return true;
      bio[x] = true;

      x = succ[x];
    }
  }

  return false;
}

bool exists(int i) {
  REP(j, A) if (g[i][j] || g[j][i]) return true;
  return false;
}

int ds[A];
int find(int x) { return ds[x] == x ? x : ds[x] = find(ds[x]); }
void merge(int x, int y) { ds[find(x)] = find(y); }

int components() {
  REP(i, A) ds[i] = i;
  REP(i, A) REP(j, A) if (g[i][j]) merge(i, j);

  int ret = 0;
  REP(i, A) if (exists(i) && find(i) == i) ++ret;
  return ret;
}

llint fact(int N) {
  llint ret = 1;
  REP(i, N) ret = ret * (i+1) % mod;
  return ret;
}

int main() {
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    int N;
    cin >> N;

    string mid = "";
    memset(g, 0, sizeof g);

    REP(i, N) {
      string s;
      cin >> s;

      int x = s.front() - 'a';
      int y = s.back() - 'a';
      ++g[x][y];

      while (!s.empty() && s.front() == x+'a') s = s.substr(1);
      while (!s.empty() && s.back() == y+'a') s = s.substr(0, s.size()-1);

      if (x == y && !s.empty()) {
        mid += "#";
        mid += 'a' + x;
        mid += "#";
        mid += 'a' + y;
        mid += "#";
      }

      mid += "#";
      mid += s;
      mid += "#";
    }

    REP(i, A) if (exists(i)) {
      mid += "#";
      mid += 'a' + i;
      mid += "#";
    }

    REP(i, A) {
      succ[i] = -1;
      REP(j, A) if (i != j && g[i][j]) succ[i] = j;
    }

    TRACE(lone_chars(mid));
    TRACE(has_multiple());
    TRACE(has_cycle());

    if (lone_chars(mid) || has_multiple() || has_cycle()) {
      printf("Case #%d: 0\n", tt);
      continue;
    }

    int C = components();

    llint ans = 1;
    ans = ans * fact(C) % mod;
    REP(i, A) ans = ans * fact(g[i][i]) % mod;

    printf("Case #%d: %lld\n", tt, ans);
  }
  return 0;
}
