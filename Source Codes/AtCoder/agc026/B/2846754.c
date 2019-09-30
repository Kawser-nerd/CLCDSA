#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int64 gcd(int64 a,int64 b){
  int64 r=a%b;
  while(r>0){
    a=b;b=r;r=a%b;
  }
  return b;
}

int cond(int64 a,int64 b,int64 c,int64 d){
  if(a<b) return 0;
  if(d<b) return 0;
  //a>=b, d>=b
  if(c>=b) return 1;
  //c<b<=a,d
  if(d%b==0){
    a=a-(a-c+b-1)/b*b;
    return a>=0;
  }
  int64 g=gcd(b,d);
  return (b-1)/g==c/g;
  /*
  a-=(a-c+b-1)/b*b;
  if(a<0) return 0;
  a+=d;
  int64 s=a;
  //c<b<=a, b<d
  //a=d..c+d
  do{
    a-=(a-c+b-1)/b*b;
    if(a<0) return 0;
    a+=d;
  } while(a!=s);
  return 1;
  */
}

void run(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int64 a,b,c,d;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    printf("%s\n",cond(a,b,c,d)?"Yes":"No");
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:49:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^
./Main.c:52:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
     ^