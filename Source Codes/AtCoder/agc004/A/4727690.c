#include<stdio.h>
int a[3], t;
int main(void){
  scanf("%d%d%d", a, a+1, a+2);
  if(a[0]<a[1]){t=a[1]; a[1]=a[0]; a[0]=t;}
  if(a[0]<a[2]){t=a[2]; a[2]=a[0]; a[0]=t;}
  printf("%ld\n", (long)(a[0]&1)*a[1]*a[2]);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", a, a+1, a+2);
   ^