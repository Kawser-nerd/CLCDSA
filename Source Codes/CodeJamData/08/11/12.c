#include <stdio.h>
#include <stdlib.h>

int cp1(const void *a, const void *b) {
  int *aa;
  int *bb;
  aa = (int *) a;
  bb = (int *) b;
  return *aa - *bb;
}

int cp2(const void *a, const void *b) {
  int *aa;
  int *bb;
  aa = (int *) a;
  bb = (int *) b;
  return *bb - *aa;
}



int main () {
  int n;
  int v1[120000];
  int v2[120000];
  int t,cs;
  int i,j;
  long long acc;

  /*  while (1) {
  scanf("%ld", &acc);
  printf("%ld", acc);
  }*/

  scanf("%d", &t);

  for (cs=1; cs<=t; cs++) {
    scanf("%d", &n);
    for (i=0;i<n;i++)
      scanf("%d", v1+i);
    for (i=0;i<n;i++)
      scanf("%d", v2+i);
    qsort(v1, n, sizeof(int), cp1);
    qsort(v2, n, sizeof(int), cp2);
    acc=0;
    for (i=0;i<n;i++)
      acc+=(v1[i]*v2[i]);
    printf("Case #%d: %ld\n", cs, acc);
  }

  return 0;
}
