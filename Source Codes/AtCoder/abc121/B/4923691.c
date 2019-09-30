#include<stdio.h>
int main(void){
  int n, m, c, b[20], a[1000][20], i, j, k, l, o, d = 0, e = 0;

  scanf("%d %d %d", &n, &m, &c);
  for(i = 0; i < m; i++) scanf("%d", &b[i]);
  for(j = 0; j < n; j++){
    for(k = 0; k < m; k++) scanf("%d", &a[j][k]);
  }
  for(l = 0; l < n; l++){
    d = 0;
    for(o = 0; o < m; o++){
      d = d + b[o]*a[l][o];
    }
    d = d + c;
    if(d > 0) e++;
  }
  printf("%d\n", e);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &n, &m, &c);
   ^
./Main.c:6:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i = 0; i < m; i++) scanf("%d", &b[i]);
                          ^
./Main.c:8:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(k = 0; k < m; k++) scanf("%d", &a[j][k]);
                            ^