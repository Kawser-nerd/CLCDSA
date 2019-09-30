#include <stdio.h>

int main(void){
  int n, m, i, j;
  scanf("%d %d", &n, &m);
  int r[2][m];
  for(i = 0; i < m; i++) scanf("%d %d", &r[0][i], &r[1][i]);
  int ans[n];
  int num;
  for(j = 0; j < n; j++){
    num = 0;
    for(i = 0; i < m; i++){
      if(r[0][i] == j + 1 || r[1][i] == j + 1) num++;
    }
    ans[j] = num;
  }
  for(i = 0; i < n; i++) printf("%d\n", ans[i]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &m);
   ^
./Main.c:7:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i = 0; i < m; i++) scanf("%d %d", &r[0][i], &r[1][i]);
                          ^