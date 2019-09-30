#include<stdio.h>

long int func(long int n,long int a){
  long int ans=0,t,flag1=0,flag2=0,flag3=0;
  t=n;

  if(n>a) return 0;
  
  while(t>0){
    if(t%10==7) flag1=1;
    else if(t%10==5) flag2=1;
    else if(t%10==3) flag3=1;
    if((flag1+flag2+flag3)==3){
      ans=1;
      break;
    }
    t/=10;
  }
  ans+=func(10*n+3,a);
  ans+=func(10*n+5,a);
  ans+=func(10*n+7,a);
  
  return ans;
}

int main(void){
  long int ans,n;    
  scanf("%ld",&n);
  ans = func(0,n);
  printf("%ld",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&n);
   ^