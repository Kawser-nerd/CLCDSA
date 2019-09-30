#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int64 comb(int n,int k){
  int64 res=1;
  int i;
  for(i=1;i<=k;i++) res=res*(n+1-i)/i;
  return res;
}

void run(void){
  int n,p;
  scanf("%d%d",&n,&p);
  int cnt[2]={0,0};
  int i;
  for(i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    cnt[a%2]++;
  }
  int64 way=0;
  for(i=p;i<=cnt[1];i+=2){
    way+=comb(cnt[1],i)*(1LL<<cnt[0]);
  }
  printf("%lld\n",way);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&p);
   ^
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^