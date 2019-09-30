#include <stdio.h>
#define MOD 1000000007
#define DMAX 1500
void divisor(int n, int *dcount, int divi[DMAX]);
long long int lcm_rush(int n, int m);
int main(void)
{
  int i, n, k, dcount = 0, divi[DMAX];
  long long int res = 0;
  scanf("%d %d", &n , &k);
  divisor(k, &dcount, divi);
  for (i = 0; i < dcount; i++) {
    res += (lcm_rush(n / divi[i], k / divi[i]) * k);
    res = (res % MOD + MOD) % MOD;
}
  printf("%lld\n", res);
}

void divisor(int n, int *dcount, int divi[DMAX])
{
  int i;
  for (i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divi[(*dcount)++] = i;
      if (n / i != i) divi[(*dcount)++] = n / i;
    }
  }
}
 
long long int lcm_rush(int n, int m)
{
  
  int i, j, pcount = 0, primes[DMAX];
  long long int res = 0;
  for (i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      primes[pcount++] = i;
      while (m % i == 0) m /= i;
    }
  }
  if (m != 1) primes[pcount++] = m;
  for (i = 0; i < (1 << pcount); i++) {
    int mu = 1, num = 1;
    long long int mnum, msum;
    for (j = 0; j < pcount; j++) {
      if (i >> j & 1) {
	mu *= -1;
	num *= primes[j];
      }
    }
    mnum = (n / num) % MOD;
    msum = (mnum * (mnum + 1) / 2) % MOD;
    res += mu * msum * (num % MOD);
    res = (res % MOD + MOD) % MOD;
  }
  return res;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n , &k);
   ^