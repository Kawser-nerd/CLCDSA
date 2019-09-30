#include<stdio.h>

int main() {
  int n, m, i;
  scanf("%d %d", &n, &m);
  int a[200010] = {};
  int b[200010] = {};
  int onetime[200010] = {};
  int possible[200010] = {};
  onetime[1] = 1;
  possible[n] = 1;
  for (i = 0; i < m; i++) {
    scanf("%d %d",&a[i], &b[i]);
    if (a[i] == 1) {
      onetime[b[i]] = 1;
    }
    if (b[i] == n) {
      possible[a[i]] = 1;
    }
  }
  int flag = 0;
  for (i = 1; i < n+1; i++) {
    if (onetime[i] == 1 && possible[i] == 1) {
      flag = 1;
    }
  }
  if (flag == 0) {
    printf("IMPOSSIBLE\n");
  } else {
    printf("POSSIBLE\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &m);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a[i], &b[i]);
     ^