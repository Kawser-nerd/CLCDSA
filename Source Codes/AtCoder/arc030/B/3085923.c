#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int calc(int r,int *a,int *b,int *h,int *used,int n){
  used[r]=1;
  int sum=0;
  int i;
  for(i=1;i<=n-1;i++){
    if(a[i]!=r && b[i]!=r) continue;
    int m=a[i]^b[i]^r;
    if(used[m]) continue;
    int c=calc(m,a,b,h,used,n);
    if(c<0) continue;
    sum+=c+2;
  }
  return sum==0 && h[r]==0?-1:sum;
}

void run(void){
  int n,x;
  scanf("%d%d",&n,&x);
  int h[101];
  int i;
  for(i=1;i<=n;i++) scanf("%d",h+i);
  int a[101];
  int b[101];
  for(i=1;i<=n-1;i++) scanf("%d%d",a+i,b+i);
  int used[101]={0};
  int ans=calc(x,a,b,h,used,n);
  printf("%d\n",ans<0?0:ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:31:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%d",h+i);
                     ^
./Main.c:34:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n-1;i++) scanf("%d%d",a+i,b+i);
                       ^