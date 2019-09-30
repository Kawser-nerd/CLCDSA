#include<stdio.h>

int main(){
  long long int x,y;
  int cnt=0;
  scanf("%lld %lld",&x,&y);
  while(x<=y){
    cnt++;
    x*=2;
  }
  printf("%d\n",cnt);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&x,&y);
   ^