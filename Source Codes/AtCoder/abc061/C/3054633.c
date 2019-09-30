#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  int64 k;
  scanf("%d%lld",&n,&k);
  int64 *cnt=(int64 *)calloc(100000+1,sizeof(int64));
  int i;
  for(i=0;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    cnt[a]+=b;
  }
  int64 c=0;
  for(i=0;c<k;i++){
    c+=cnt[i];
  }
  printf("%d\n",i-1);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%lld",&n,&k);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^