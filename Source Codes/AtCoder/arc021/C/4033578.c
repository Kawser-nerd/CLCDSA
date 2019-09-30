#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

void run(void){
  int k,n;
  scanf("%d%d",&k,&n);
  int *a=(int *)calloc(n,sizeof(int));
  int *d=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d%d",a+i,d+i);
  int64 l=0;
  int64 r=1000000000000LL;
  while(r-l>1){
    int64 m=(l+r)/2;
    int64 cnt=0;
    for(i=0;i<n;i++){
      if(a[i]>m) continue;
      cnt+=1+(m-a[i])/d[i];
    }
    if(cnt<k){
      l=m;
    } else {
      r=m;
    }
  }
  int64 sum=0;
  for(i=0;i<n;i++){
    if(a[i]>r) continue;
    int cnt=1+(r-a[i])/d[i];
    k-=cnt;
    sum+=(int64)cnt*a[i]+(int64)cnt*(cnt-1)/2*d[i];
  }
  printf("%lld\n",sum+r*k);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&k,&n);
   ^
./Main.c:12:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d",a+i,d+i);
                    ^