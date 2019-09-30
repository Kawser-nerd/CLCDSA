#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib>

using namespace std;

long long modpow(long long a, long long p, long long m)
{
  long long res = 1;
  a %= m;
  while(p)
  {
    if (p % 2) {
      res *= a;
      res %= m;
    }
    a *= a;
    a %= m;
    p /= 2;
  }
  return res;
}

int main()
{
  int n, A, B;
  scanf("%d%d%d", &n, &A, &B);
  vector<int> dat(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &dat[i]);
  }
  const int mod = 1000000007;
  sort(dat.begin(), dat.end());
  if (A == 1) {
    for (int i = 0; i < n; i++) {
      printf("%d%c", dat[i], " \n"[i+1 == n]);
    }
    return 0;
  }
  while (B > 0) {
    if ((long long)dat[0] * A >= dat[n - 1])
      break;
    dat[0] *= A;
    inplace_merge(dat.begin(), dat.begin() + 1, dat.end());
    B--;
  }
  int quo = B / n;
  int rem = B % n;
  for (int i = 0; i < n; i++) {
    int mulcnt = quo;
    if (i < rem) {
      mulcnt++;
    }
    dat[i] = (int)(dat[i] * modpow(A, mulcnt, mod) % mod);
  }
  rotate(dat.begin(), dat.begin() + rem, dat.end());
  for (int i = 0; i < n; i++) {
    printf("%d\n", dat[i]);
  }
  return 0;
}