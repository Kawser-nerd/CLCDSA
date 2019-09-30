#include<stdio.h>
int n, a, b;
long ans;
int main(){
  scanf("%d%d%d", &n ,&a, &b);
  ans = ((long)n-2)*(b-a)+1;
  printf("%ld\n", ans>=0?ans:0);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &n ,&a, &b);
   ^