#include<stdio.h>
int a, b, c;
int ans, i, j;
int main(){
  scanf("%d%d", &a, &b);
  c = b-a;
  ans = c*(c+1)/2 - b;
  printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^