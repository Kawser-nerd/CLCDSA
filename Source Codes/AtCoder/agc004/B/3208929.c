#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MIN(a,b) ((a)<(b)?(a):(b))

void run(void){
  int n,x;
  scanf("%d%d",&n,&x);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int *min=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) min[i]=a[i];
  int64 ans=(int64)1000000000*n;
  int k;
  for(k=0;k<n;k++){
    int64 local=(int64)k*x;
    for(i=0;i<n;i++) local+=min[i];
    ans=MIN(ans,local);
    for(i=0;i<n;i++) min[i]=MIN(min[i],a[(i-k-1+n)%n]);
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:13:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^