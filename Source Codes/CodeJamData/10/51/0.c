#include <stdio.h>

#define MAXM 1000001

char notprime[MAXM];

void init() {
  int i, j;
  for (i = 2; i < MAXM; ++i)
    if (notprime[i] == 0) {
      if (MAXM / i >= i) {
	for (j = i * i; j < MAXM; j += i)
	  notprime[j] = 1;
      }
    }
}

#define MAXK 11
long long seq[MAXK];
int k, d, maxp;

void solve(int c);

int main() {
  int t, c, i;

  init();

  //  printf("%d\n", inverse(13, 4));

  scanf("%d\n", &t);
  for (c = 1; c <= t; ++c) {
    scanf("%d %d\n", &d, &k);
    for (i = 0; i < k; ++i)
      scanf("%lld", seq+i);
    solve(c);
  }
  return 0;
}

int simple_predict(int p, int a, int b, int *c) {
  int i;
  int s;
  for (i = 0; i < k; ++i)
    if (seq[i] >= p)
      return 0;

  s = seq[0];
  for (i = 1; i < k; ++i) {
    s = (a * s + b) % p;
    if (s != seq[i])
      return 0;
  }
  *c = (a * s + b) % p;
  return 1;
}

void ex_gcd(int a, int b, int *x, int *y) {
  int t;

  if (a == 0) {
    *y = b;
    *x = 0;
    return;
  }
  t = (b / a);
  ex_gcd(b - a * t, a, y, x);
  *x = (*x - t * *y) % b;
}

int inverse(int p, int a) {
  int x, y;
  if (a < 0) 
    a += p;
  ex_gcd(a, p, &x, &y);
  if (x < 0)
    return (p + x);
  else
    return x;
}

int pred(int p, int *c) {
  long long s = seq[0];
  long long a, b, x;
  int i;

  for (i = 0; i < k; ++i)
    if (seq[i] >= p)
      return 0;

  if (seq[0] == seq[1]) {
    *c = seq[0];
    return 1;
  }
  else {
    if (k <= 2)
      return 0;
    if ((seq[0] + seq[2] - seq[1] * 2) % p == 0) {
      a = 1; b = (p + seq[1] - seq[0]) % p;
      for (i = 1; i < k; ++i) {
	s = (a * s + b) % p;
	if (s != seq[i])
	  return 0;
      }
      *c = (a * s + b) % p;
      return 1;
    }
    else {
      x = (seq[1] * seq[1] - seq[0] * seq[2]) % p * inverse(p, seq[0] + seq[2] - 2 * seq[1]) % p;
      if (x < 0)
	x += p;
      a = inverse(p, (seq[0] + x)) * (seq[1] + x) % p;
      if (a < 0) 
	a += p;
      b = (a - 1) * x % p;
      if (b < 0)
	b += p;

      for (i = 1; i < k; ++i) {
	s = (a * s + b) % p;
	if (s != seq[i])
	  return 0;
      }
      *c = (a * s + b) % p;
      return 1;
    }
  }
}

void solve(int c) {
  int i;
  int prev, curr;
  int a, b;

  maxp = 1;
  for (i = 0; i < d; ++i)
    maxp *= 10;

  prev = -1;
  for (i = 2; i <= maxp; ++i) 
    if (notprime[i] == 0) {
      if (i <= 20) {
	for (a = 0; a < i; ++a)
	  for (b = 0; b < i; ++b)
	    if (simple_predict(i, a, b, &curr)) {
	      if (prev == -1 || curr == prev)
		prev = curr;
	      else {
		printf("Case #%d: I don't know.\n", c);
		return;
	      }
	    }
      }
      else {
	if (pred(i, &curr)) {
	  if (prev == -1 || curr == prev)
	    prev = curr;
	  else {
	    printf("Case #%d: I don't know.\n", c);
	    return;
	  }
	}
      }
    }
  if (prev == -1)
    printf("Case #%d: I don't know.\n", c);
  else
    printf("Case #%d: %d\n", c, prev);
}
