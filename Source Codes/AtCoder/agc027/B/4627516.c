#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

void run(void){
  int n,y;
  scanf("%d%d",&n,&y);
  int *x=(int *)calloc(n,sizeof(int));
  int i,j;
  for(i=0;i<n;i++) scanf("%d",x+i);
  int64 *xsum=(int64 *)calloc(n+1,sizeof(int64));
  for(i=1;i<=n;i++) xsum[i]=xsum[i-1]+x[i-1];
  int64 ans=1000000000LL*5*200000+1000000000LL*400000;;
  for(i=1;i<=n;i++){
    int64 sum=(int64)y*(n+i);
    int k=1;
    for(j=n;j>0;j-=i,k++){
      sum+=(k==1?5:1+2*k)*(xsum[j]-xsum[MAX(0,j-i)]);
      if(sum>ans) break;
    }
    ans=MIN(ans,sum);
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&y);
   ^
./Main.c:14:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",x+i);
                    ^