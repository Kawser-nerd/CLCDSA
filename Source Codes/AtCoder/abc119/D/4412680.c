#include <stdio.h>
#include <stdlib.h>

#define INF  10000000000000

int search(long key, long v[], int n)
{
  long l = 0;
  long r = n - 1;
  long i;
  while (r - l >= 1) {
    i = (l + r) / 2;
    if (key > v[i])
      l = i + 1;
    else
      r = i;
  }
  if (key  > v[i])
    return i + 1;
  else
    return i;
}

long min3(long a, long b, long c)
{
  long min = a;

  if (b < min) min = b;
  if (c < min) min = c;
  return min;
}      
  
int main(void)
{
  int a, b, q;
  long s[100002];
  long t[100002];
  long x[100000];
  int c, d;

  scanf("%d %d %d", &a, &b, &q);
  s[0] = -INF;   s[a + 1] = INF;
  t[0] = -INF;   t[b + 1] = INF;
  for (int i = 1; i <= a; i++) 
    scanf("%ld", &s[i]);
  for (int i = 1; i <= b; i++)
    scanf("%ld", &t[i]);
  for (int i = 0; i < q; i++) 
    scanf("%ld", &x[i]);
    
  for (int i = 0; i < q; i++) {
    c = search(x[i], s, a + 2);
    d = search(x[i], t, b + 2);
    long res = INF;
    for (int j = c - 1; j <= c; j++) {
      for (int k = d - 1; k <= d; k++) {
	long d1 = labs(s[j] - x[i]) + labs(t[k] - s[j]);
	long d2 = labs(t[k] - x[i]) + labs(s[j] - t[k]);
	res = min3(res, d1, d2);
      }
    }
    printf("%ld\n", res);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &a, &b, &q);
   ^
./Main.c:45:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &s[i]);
     ^
./Main.c:47:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &t[i]);
     ^
./Main.c:49:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &x[i]);
     ^