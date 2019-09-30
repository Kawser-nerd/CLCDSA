#include<stdio.h>
int main(){
  int n,k,s=1;
  scanf("%d%d",&n,&k);
  while(n){
    s+=s>k?k:s;
    n--;
  }
  printf("%d",s);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^