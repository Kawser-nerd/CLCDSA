#include <stdio.h>
#include <stdlib.h>
#define ALP 26

int compare_int(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
  int c = 1,alp1[ALP],alp2[ALP];
  for (int i = 0; i < ALP; i++) {
    alp1[i] = 0;
    alp2[i] = 0;
  }
  char s;
  while(scanf("%c",&s) != EOF && s != '\n') alp1[s-97]++;
  while(scanf("%c",&s) != EOF && s != '\n') alp2[s-97]++;
  qsort(alp1,26,sizeof(int),compare_int);
  qsort(alp2,26,sizeof(int),compare_int);
  for (int i = 0; i < ALP; i++) {
    if (alp1[i] == alp2[i]) c *= 1;
    else c *= 0;
  }
  if (c == 1) printf("Yes\n");
  else printf("No\n");
  return 0;
}