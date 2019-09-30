# include <stdio.h>

int main(){
  int a[3];
  scanf("%d %d %d",&a[0],&a[1],&a[2]);
  if((10*a[1]+a[2])%4==0) puts("YES");
  else puts("NO");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a[0],&a[1],&a[2]);
   ^