#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int *a=(int *)malloc(sizeof(int)*(n+1));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  a[n]=0;
  int64 sum=0;
  for(i=0;i<k;i++) sum+=a[i];
  int64 l=0;
  int64 r=0;
  for(i=k;i<n;i++) if(a[i]>0) r+=a[i];
  int64 max=l+r+MAX(sum,0);;
  for(i=1;i+k-1<n;i++){
    if(a[i-1]>0) l+=a[i-1];
    if(a[i+k-1]>0) r-=a[i+k-1];
    sum+=a[i+k-1]-a[i-1];
    max=MAX(max,l+r+MAX(sum,0));
  }
  printf("%lld\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:15:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^