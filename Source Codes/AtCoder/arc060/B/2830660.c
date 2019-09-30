#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int64 f(int64 n,int b){
  int64 res=0;
  while(n>0){
    res+=n%b;
    n/=b;
  }
  return res;
}

void run(void){
  int64 n,s;
  scanf("%lld%lld",&n,&s);
  int b;
  for(b=2;(int64)b*b<=n;b++){
    if(f(n,b)==s){
      printf("%d\n",b);
      return;
    }
  }
  //n=xp+y
  int64 x;
  for(x=n/b;x>=1;x--){
    int64 y=s-x;
    if(!(y>=0 && n-y>0 && (n-y)%x==0)) continue;
    int64 p=(n-y)/x;
    if(x<p && y<p && n==x*p+y){
      printf("%lld\n",p);
      return;
    }
  }
  if(n==s){
    printf("%lld\n",n+1);
  } else {
    printf("-1\n");
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&n,&s);
   ^