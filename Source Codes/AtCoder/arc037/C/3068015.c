#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

int count(int *a,int n,int64 v){
  if(a[0]>v) return 0;
  int l=0;
  int r=n;
  while(r-l>1){
    int m=(l+r)/2;
    if(a[m]<=v){
      l=m;
    } else {
      r=m;
    }
  }
  return r;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int *a=(int *)malloc(sizeof(int)*n);
  int *b=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  for(i=0;i<n;i++) scanf("%d",b+i);
  qsort(b,n,sizeof(int),cmp);
  int64 l=0;
  int64 r=1000000000000000000LL;
  while(r-l>1){
    int64 m=(l+r)/2;
    int cnt=0;
    int i;
    for(i=0;i<n;i++){
      cnt+=count(b,n,m/a[i]);
    }
    if(cnt>=k){
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
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:36:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^
./Main.c:37:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",b+i);
                    ^