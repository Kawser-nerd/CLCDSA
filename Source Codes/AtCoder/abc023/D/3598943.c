#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

int *cnt=NULL;
int can(int64 m,int *h,int *s,int n){
  int i;
  for(i=0;i<n;i++) cnt[i]=0;
  for(i=0;i<n;i++){
    if(h[i]>m) return 0;
    int64 index=(m-h[i])/s[i];
    if(index>n-1) index=n-1;
    cnt[index]++;
  }
  int sum=cnt[0];
  for(i=1;i<n;i++){
    if(sum>i) return 0;
    sum+=cnt[i];
  }
  return 1;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *h=(int *)calloc(n,sizeof(int));
  int *s=(int *)calloc(n,sizeof(int));
  cnt=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d%d",h+i,s+i);
  int64 l=0;
  int64 r=1000000000+(int64)(100000-1)*1000000000;
  while(r-l>1){
    int64 m=(l+r)/2;
    if(can(m,h,s,n)){
      r=m;
    } else {
      l=m;
    }
  }
  printf("%lld\n",r);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:31:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d",h+i,s+i);
                    ^