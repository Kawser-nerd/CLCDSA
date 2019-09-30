#include<stdio.h>
int main(){
  int n,l,r,s=0;
  scanf("%d",&n);
  while(n--){
    scanf("%d%d",&l,&r);
    s+=r-l+1;
  }
  printf("%d",s);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&l,&r);
     ^