#include <stdio.h>

typedef __uint128_t lo;

lo powmod(lo a, lo b, lo c)
{
  if (b == 0) return 1;
  if (b == 1) return a % c;

  lo p = powmod(a, b >> 1, c);
  p = (p * p) % c;
  if (b & 1) p = (p * a) % c;
  return p;
}

int n_bases = 7;
int bases[7] = {2, 3, 5, 7, 11, 13, 17};

char rabin(lo n)
{
  if (n == 2) return 1;
  if (n == 1 || (n % 2) == 0) return 0;

  lo r = 0, s = n - 1;
  while (!(s & 1)) {
    s >>= 1;
    r++;
  }

  for (int i = 0; i < n_bases; i++) {
    lo b = bases[i];
    if (b >= n) break;

    b = powmod(b, s, n);
    if (b == 1 || b == n - 1) continue;

    char found = 0;
    for (int j = 0; j < r - 1; j++) {
      b = (b * b) % n;
      if (b == n - 1) {
        found = 1;
        break;
      }
    }
    if (!found) {
      return 0;
    }
  }
  return 1;
}

lo factor(lo n)
{
  for (lo f = 2; f < 100000; f += 1 + (f != 2)) {
    if (!(n % f)) {
      return f;
    }
  }
  return 0;
}

#define b0 2
#define b1 10

void go(int N, int J)
{
  lo pows[b1 + 1][N];
  for (int b = b0; b <= b1; b++) {
    pows[b][0] = 1;
    for (int p = 1; p < N; p++) {
      pows[b][p] = b * pows[b][p - 1];
    }
  }

  for (unsigned long bin = (1L << (N - 1)) + 1; bin < (1L << N); bin += 2) {
    lo vals[b1 + 1];
    for (int b = b0; b <= b1; b++) {
      vals[b] = 0;
    }
    for (int d = 0; d < N; d++) {
      if (bin & (1 << d)) {
        for (int b = b0; b <= b1; b++) {
          vals[b] += pows[b][d];
        }
      }
    }

    char good = 1;
    for (int b = b0; b <= b1; b++) {
      if (rabin(vals[b])) {
        good = 0;
        break;
      }
    }
    if (good) {
      lo factors[b1 + 1];
      for (int b = b0; b <= b1; b++) {
        if(!(factors[b] = factor(vals[b]))){
          good = 0;
          break;
        }
      }
      if(!good){
        continue;
      }

      for (int d = N - 1; d >= 0; d--) {
        printf("%lu", (bin >> d) & 1);
      }
      fflush(stdout);
      for (int b = b0; b <= b1; b++) {
        printf(" %llu", (long long unsigned)factors[b]);
        fflush(stdout);
      }
      puts("");
      if (!--J) {
        return;
      }
    }
  }
}

int main()
{
  int T, N, J;
  int ret;
  ret = scanf("%d", &T);
  for(int i = 0; i < T; i++){
    ret = scanf("%d %d", &N, &J);
    printf("Case #%d:\n", i + 1);
    go(N, J);
  }
}
