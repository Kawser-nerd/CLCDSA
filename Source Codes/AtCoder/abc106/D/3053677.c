#include <stdio.h>
#define N 502

int main (void) {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);

  int a[N][N] = {{0}};  
  for (int i = 0; i < m; i++)  {
    int l, r;
    scanf("%d %d", &l, &r);
    a[l][r]++;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
  
  for (int i = 0; i < k; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    printf("%d\n", a[q][q] - a[p-1][q] - a[q][p-1] + a[p-1][p-1]);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &n, &m, &k);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &l, &r);
     ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &p, &q);
     ^