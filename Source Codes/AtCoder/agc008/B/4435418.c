#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int64 sum=0;
  for(i=0;i<k;i++) sum+=a[i];
  int64 free=0;
  for(i=k;i<n;i++) free+=MAX(0,a[i]);
  int64 max=MAX(0,sum)+free;
  for(i=1;i+k-1<n;i++){
    free-=MAX(a[i+k-1],0);
    free+=MAX(a[i-1],0);
    sum-=a[i-1];
    sum+=a[i+k-1];
    max=MAX(max,MAX(sum,0)+free);
  }
  printf("%lld\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:13:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^