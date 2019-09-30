#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int h,w,d;
  scanf("%d%d%d",&h,&w,&d);
  int *x=(int *)malloc(sizeof(int)*(h*w+1));
  int *y=(int *)malloc(sizeof(int)*(h*w+1));
  int i,j;
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      int n;
      scanf("%d",&n);
      x[n]=i;
      y[n]=j;
    }
  }
  int *dp=(int *)calloc(h*w+1,sizeof(int));
  for(i=d;i<=h*w;i++){
    dp[i]=dp[i-d]+ABS(x[i]-x[i-d])+ABS(y[i]-y[i-d]);
  }
  int q;
  scanf("%d",&q);
  for(i=0;i<q;i++){
    int l,r;
    scanf("%d%d",&l,&r);
    printf("%d\n",dp[r]-dp[l]);
  }
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&h,&w,&d);
   ^
./Main.c:20:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&n);
       ^
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&l,&r);
     ^