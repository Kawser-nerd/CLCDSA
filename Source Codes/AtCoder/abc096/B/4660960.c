#include<stdio.h>
int max2(int a, int b){return a<b?b:a;}
int a, b, c, max, ans;
int k;
int main(){
  scanf("%d%d%d%d", &a, &b, &c, &k);
  ans = a+b+c;
  max = max2(a, max2(b, c));
  ans -= max;
  ans += max<<k;
  printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d", &a, &b, &c, &k);
   ^