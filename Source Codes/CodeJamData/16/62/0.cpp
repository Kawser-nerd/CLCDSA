#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += md;
  }
}

inline int mul(int a, int b) {
  return (long long) a * b % md;
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

inline int inv(int x) {
  return power(x, md - 2);
}

const int N = 10000023;

int f[N], s[N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  f[0] = 1; f[1] = 0;
  s[0] = 1; s[1] = 1;
  for (int i = 2; i < N; i++) {
    f[i] = mul(s[i - 2], inv(i));
    s[i] = s[i - 1];
    add(s[i], f[i]);
  }
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n, k;
    scanf("%d %d", &n, &k);
    int l = k - 1, r = n - k;
    printf("%d\n", (md + 1 - mul(f[l], f[r])) % md);
    fprintf(stderr, "test case %d solved\n", qq);
    fflush(stderr);
  }
  return 0;
}
