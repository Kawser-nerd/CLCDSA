#include <stdio.h>
#define LL long long int

LL invmod(LL a, LL b) {
  LL r, r1, u, v, q, rs, us, vs, u1, v1;
  r = a;  r1 = b;
  u = 1; v = 0;
  u1 = 0; v1 = 1;
  while ( r1) {
    q = r / r1;
    rs = r;
    us = u;
    vs = v;
    r = r1;
    u = u1;
    v = v1;
    r1 = rs - q * r1;
    u1 = us - q * u1;
    v1 = vs - q * v1;
	  }
  return u % b;
}

LL ps[10002][10002];
LL ws[10002][10002];
LL invs[10002];
LL MOD = 1000000007;
int main() {
  for (LL i =1; i < 10001; i++) {
    invs[i] = invmod(i, MOD);
  }
  ps[0][0] = 1;
  ws[0][1] = 1;
  for (LL z = 1; z < 10000 + 1; z++) {
    for (LL j = 0; j <= z; j++) {
      LL i = z - j;
           LL u = invs[i + j];
      LL a =0;
      if (i >= 1) a += ws[j][i - 1];
      if (j >= 1) a += ws[i][j - 1];
      a = (u * a) % MOD;
      ps[i][j] = a;
      ws[i][j+1] = (a + ws[i][j]) % MOD;
    }
  }

  int t; scanf("%d", &t);
  for (int _ = 0; _ < t; _++) {
  int k, i; scanf("%d %d", &k, &i);
  i--;
  LL u = ps[i][k-i-1];
  printf("Case #%d: %lld\n", _+1, (MOD-u+1) % MOD);
  }
}
