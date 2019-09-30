#include <stdio.h>
int main(void){
  int n;
  scanf("%d",&n);
  int l,r,i,sum=0;
  for(i=0;i<n;i++){
    scanf("%d%d",&l,&r);
    sum+=r-l+1;
  }
  if(sum>=100000) sum=100000;
  printf("%d",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&l,&r);
     ^