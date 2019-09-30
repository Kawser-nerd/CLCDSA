#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline int mul(int a, int b) {
  return (long long)a * b % md;
}

inline int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    b >>= 1;
    a = mul(a, a);
  }
  return res;
}

inline int inv(int a) {
  return power(a, md - 2);
}

const int N = 2000010;

int fact[N], invfact[N], der[N];

inline int C(int n, int k) {
  return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int main(int argc, char* argv[]) {
  int TEST_FROM = 0;
  int TEST_TO = 123456789;
  if (argc == 3) {
    sscanf(argv[1], "%d", &TEST_FROM);
    sscanf(argv[2], "%d", &TEST_TO);
  }
  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  fact[0] = invfact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
    invfact[i] = mul(invfact[i - 1], inv(i));
  }
  der[0] = 1;
  for (int i = 1; i < N; i++) {
    der[i] = mul(der[i - 1], i);
    if (i & 1) {
      add(der[i], md - 1);
    } else {
      add(der[i], 1);
    }
  }
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    // input data starts
    int n, x;
    scanf("%d %d", &n, &x);
    // input data ends
    if (qq < TEST_FROM || qq > TEST_TO) {
      continue;
    }
    printf("Case #%d: ", qq);
    fflush(stdout);
    // solution starts
    int ans = 0;
    for (int pts = x; pts <= n; pts++) {
      add(ans, mul(der[n - pts], C(n, pts)));
    }
    printf("%d\n", mul(ans, fact[n]));
    // solution ends
    fflush(stdout);
    fprintf(stderr, "test %d solved\n", qq);
  }
  return 0;
}
