#include <stdio.h>

#define MAX 100

int t, r, n, m, k, try[MAX], count;

int find_max() {
  int i, j, max, which, aux;
  which = 2;
  for (j=max=0; j<k; j++)
    if (try[j]%2==0 && try[j]%4!=0)
      max++;
  for (i=3; i<=6; i++) {
    for (j=aux=0; j<k; j++)
      if (try[j]%i==0) aux++;
    if (aux>max) {
      max = aux;
      which = i;
    }
  }
  return which;
}

int main() {
  int i, j, l, w;

  scanf("%d", &t);
  scanf("%d %d %d %d", &r, &n, &m, &k);  
  printf("Case #1:\n");

  for (i=0; i<r; i++) {
    for (j=0; j<k; j++) scanf("%d\n", &try[j]);

    for (j=0; j<n; j++) {
      w = find_max();
      printf("%d", w);
      for (l=0; l<k; l++)
	if (try[l]%w==0) try[l]/=w;
    }
    putchar('\n');
  }

  return 0;
}
