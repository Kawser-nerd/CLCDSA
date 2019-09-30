#include<stdio.h>

int main(void){
  long long iu,mr,mb,r,b,x,y,s=0,f=1234567890123456789ll,t;
  scanf("%lld%lld%lld%lld",&r,&b,&x,&y);
  while(s<=f){
    t=(s+f)/2ll;
    mr=r-t;mb=b-t;
    if(mr<0ll || mb<0ll){f=t-1;continue;}
    iu=((mr/(x-1ll))+(mb/(y-1ll)));
    if(iu<t){f=t-1ll;}else{s=t+1ll;}
  }
  printf("%lld\n",f);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld",&r,&b,&x,&y);
   ^