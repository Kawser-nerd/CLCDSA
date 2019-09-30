#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

void run(void){
  int n,x;
  scanf("%d%d",&n,&x);
  int a;
  scanf("%d",&a);
  int64 ans=0;
  if(a>x){
    ans+=a-x;
    a=x;
  }
  while(--n){
    int b;
    scanf("%d",&b);
    if(a+b>x){
      ans+=a+b-x;
      b-=a+b-x;
    }
    a=b;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^