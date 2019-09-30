#include <cstdio>
#include <cassert>

#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x" = " << x << endl
#define _ << " _ " <<

typedef long long llint;

char s[100];

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt) {
    scanf("%s", s);
    for (char *c = s; *c; ++c) if (*c == '/') *c = ' ';

    llint P, Q;
    stringstream ss(s);
    ss >> P >> Q;

    llint g = __gcd(P, Q);
    P /= g;
    Q /= g;

    llint B = 1LL << 40;

    if (B % Q) {
      printf("Case #%d: impossible\n", tt);
      continue;
    }

    llint A = B / Q * P;

    int i = 40;
    while ((1LL << i) > A) --i;

    printf("Case #%d: %d\n", tt, 40-i);
  }
  return 0;
}
