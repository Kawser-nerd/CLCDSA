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

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *a=(int *)malloc(sizeof(int)*(n+1));
  int i;
  for(i=1;i<=n;i++) scanf("%d",a+i);
  a[0]=0;
  for(i=1;i<=n;i++){
    a[i]+=a[i-1];
    a[i]%=m;
  }
  qsort(a,n+1,sizeof(int),cmp);
  int64 ans=0;
  i=0;
  while(i<=n){
    int j=i+1;
    while(j<=n && a[j]==a[i]) j++;
    int d=j-i;
    ans+=(int64)d*(d-1)/2;
    i=j;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:20:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%d",a+i);
                     ^