#include <stdio.h>

#define MAX 1024 * 1024 * 16
static int result[16][MAX];
static int count;

int next (int n, int base)
{
  int r, nn, sum = 0;
  nn = n;
  if (result[base][n])
    return result[base][n];
  result[base][n] = count;
  while (n > 0) {
    r = n % base;
    n /= base;
    sum += r*r;
  }
  r = next (sum, base);
  result[base][nn] = r;
  return r;
}

void calculate (void)
{
  int i, j, base;
  for (base = 2; base <= 10; base++) {
    count = 2;
    result[base][1] = 1;
    for (i = 1; i < MAX; i++) {
      if (result[base][i] == 0) {
        next (i, base);
      }
      if (result[base][i] == count) {
	count++;
      }
     }
  }
}

int main (void)
{
  int T, test;
  char buffer[512];
  int i, j, bases[16];
  calculate ();
  
  scanf (" %d ", &T);
  for (test = 1; test <= T; test++) {
    int len = 0, aux;
    char *s = fgets (buffer, sizeof (buffer), stdin);
    for (i = 2; i <= 10; i++) bases[i] = 0;
    while (1) {
      if (!sscanf (&s[len], "%d%n", &i, &aux)) break;
      bases[i] = 1;
      len += aux;
    }
    printf ("Case #%d: ", test);
    for (i = 2; i < MAX; i++) {
      for (j = 2; j <= 10; j++) {
	if (bases[j]){
	  if (result[j][i] != 1) break;
	}
      }
      if (j > 10) break;
    }
    printf ("%d\n", i);
  }
  return 0;
}
