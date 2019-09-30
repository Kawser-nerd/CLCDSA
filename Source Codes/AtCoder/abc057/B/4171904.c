#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n, m, i, j, temp, min;
  scanf("%d %d", &n, &m);
  int s[n][n];
  int c[m][m];
  for(i = 0; i < n; i++) scanf("%d %d", &s[0][i], &s[1][i]);
  for(i = 0; i < m; i++) scanf("%d %d", &c[0][i], &c[1][i]);
  int ans[n];
  for(i = 0; i < n; i++) ans[i] = 1000000000;
  temp = 0;
  int num;
  for(i = 0; i < n; i++){
    min = ans[i];
    for(j = 0; j < m; j++){
      temp = abs(s[0][i] - c[0][j] ) + abs(s[1][i] - c[1][j]);
      if(temp < min){
	num = j + 1;
	min = temp;
      }
    }
    ans[i] = num;
  }
  
  for(i = 0; i < n; i++) printf("%d\n", ans[i]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &m);
   ^
./Main.c:9:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i = 0; i < n; i++) scanf("%d %d", &s[0][i], &s[1][i]);
                          ^
./Main.c:10:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i = 0; i < m; i++) scanf("%d %d", &c[0][i], &c[1][i]);
                          ^