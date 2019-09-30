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
  const int m=100000;
  int *cnt=(int *)calloc(m+1,sizeof(int));
  int i;
  for(i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    cnt[a]++;
  }
  int x=0;
  int y=0;
  for(i=1;i<=m;i++){
    while(cnt[i]>=3){
      cnt[i]-=2;
    }
    if(cnt[i]>=2) y++;
    if(cnt[i]>=1) x++;
  }
  while(y>=2) y-=2;
  printf("%d\n",x-y);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^