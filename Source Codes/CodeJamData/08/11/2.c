#include <stdio.h>
#include <stdlib.h>

#define MAX 801

int n;
long long v1[MAX], v2[MAX];
long long sum;

int compare(const void *a, const void *b) {
  long long *n1 = (long long *)a;
  long long *n2 = (long long *)b;
  if (*n1 < *n2) return -1;
  if (*n1 > *n2) return 1;
  return 0;
}

int main() {
  int i, j, k, ncases;

  scanf("%d",&ncases);
  for (i=1; i<=ncases; i++) {
    scanf("%d",&n);
    for (j=0; j<n; j++) scanf("%lld",&v1[j]);
    for (j=0; j<n; j++) scanf("%lld",&v2[j]);

    qsort(v1, n, sizeof(long long), compare);
    qsort(v2, n, sizeof(long long), compare);
    
    sum = 0;
    
    for (j=0, k=n-1 ; j<n; j++, k--) {
      sum += v1[j]*v2[k];
    }

    printf("Case #%d: %lld\n",i, sum);
  }

  return 0;
}
