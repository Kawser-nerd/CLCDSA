#include <stdio.h>
#include <string.h>

#define MAX 2501

int v[MAX];

int main() {
  int t, i, j, k, n, aux;
  
  scanf("%d", &t);
  for (i=1; i<=t; i++) {
    scanf("%d", &n);
    memset(v, 0, sizeof(v));
    for (j=0; j<2*n-1; j++)
      for (k=0; k<n; k++) { 
	scanf("%d", &aux);
	v[aux]++;
      }
    printf("Case #%d:", i);
    for (j=1; j<MAX; j++)
      if (v[j]%2==1) printf(" %d", j);
    puts("");
  }
  
  return 0;
}
