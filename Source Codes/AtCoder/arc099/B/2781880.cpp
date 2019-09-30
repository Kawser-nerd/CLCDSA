//Author: 23forever
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
typedef long long LL;
const int MAXN = 1000000; 
using namespace std;

inline int read() {
  int x = 0, w = 1;
  char c = ' ';

  while (c < '0' || c > '9') {
    c = getchar();
    if (c == '-') w = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }

  return x * w;
}

int k;

void init() {
  k = read();
}

LL a[MAXN + 5];
LL nine[MAXN + 5];
int tot = 0;

inline int getSum(LL x) {
  LL t = x, ret = 0;

  while (t) {
    ret += t % 10;
    t /= 10;
  }

  return ret;
}

bool cmp(LL x, LL y) {
  LL a = x * getSum(y), b = y * getSum(x);
  
  if (a != b) {
    return a < b;
  } else {
    return x < y;
  }
}

int main() {
  init();

  for (int i = 1; i <= 15; ++i) 
    nine[i] = nine[i - 1] * 10 + 9;

  for (int i = 1; i <= 999; ++i) {
    LL tmp = 1;
    a[++tot] = i;
    for (int j = 1; j <= 12; ++j) {
      tmp *= 10;
      a[++tot] = i * tmp + nine[j];
    }
  }
  
  sort(a + 1, a + 1 + tot, cmp);
  unique(a + 1, a + 1 + tot);
    
  LL mx = 0;
  int i = 1;

  while (k) {
    if (a[i] > mx) {
      mx = a[i];
      --k;
      printf("%lld\n", a[i]);
    }
    
    ++i;
  }

  return 0;
}