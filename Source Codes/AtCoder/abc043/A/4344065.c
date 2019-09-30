#include<stdio.h>

int sum(int n){
  if(n==0) return 0;
  else return n+sum(n-1);
}

int main(void){
  int n,ans;
  scanf("%d",&n);
  ans=sum(n);
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^