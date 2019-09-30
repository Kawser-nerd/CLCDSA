#include <stdio.h>
int main(){
  int n,d,x,a[100],i,sum=0;
  scanf("%d%d%d",&n,&d,&x);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    sum+=d/a[i]+(d%a[i]!=0);
  }
  printf("%d",sum+x);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&d,&x);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^