#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int n, a[100001], ans = 0, soe = 1, flag = 0;

  if(scanf("%d", &n) == 1);

  for(int i = 0; i < n; i++) {
    if(scanf("%d", &a[i]) == 1);
  }

  for(int i = 0; i < n; i++) {
    ans++;
    if((soe = a[soe - 1]) == 2) {
      printf("%d", ans);
      flag = 1;
      break;
    }
  }

  if(!flag) {
    printf("-1");
  }

  return 0;
}