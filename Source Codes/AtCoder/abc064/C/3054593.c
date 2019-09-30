#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  int cnt[9]={0};
  int i;
  for(i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    cnt[MIN(8,a/400)]++;
  }
  int ans=0;
  for(i=0;i<8;i++){
    if(cnt[i]>0){
      ans++;
    }
  }
  int min=(ans>0?ans:1);
  int max=ans+cnt[8];
  printf("%d %d\n",min,max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^