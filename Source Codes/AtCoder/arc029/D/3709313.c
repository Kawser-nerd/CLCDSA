#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*(n+1)+(j))

typedef struct ftedge{
  int a,b;
} edge;

int cmpEdge(const void *a,const void *b){
  return ((edge *)a)->b-((edge *)b)->b;
}

int cmpInt(const void *a,const void *b){
  return -(*(int *)a-*(int *)b);
}

void run(void){
  int n;
  scanf("%d",&n);
  const int64 ini=5000000000000LL+1;
  int64 *dp=(int64 *)calloc((n+1)*(n+1),sizeof(int64));
  int i,j;
  for(i=0;i<=n;i++) for(j=0;j<=n;j++) dp[POS(i,j)]=ini;
  for(i=1;i<=n;i++) scanf("%lld",dp+POS(i,1));
  edge *e=(edge *)calloc(n-1,sizeof(edge));
  for(i=0;i<n-1;i++) scanf("%d%d",&e[i].a,&e[i].b);
  qsort(e,n-1,sizeof(edge),cmpEdge);
  for(i=n-2;i>=0;i--){
    const int a=e[i].a;
    const int b=e[i].b;
    int alen=1;
    int blen=1;
    while(dp[POS(a,alen+1)]!=ini) alen++;
    while(dp[POS(b,blen+1)]!=ini) blen++;
    for(j=alen;j>=1;j--){
      for(int k=1;k<=blen;k++){
	dp[POS(a,j+k)]=MIN(dp[POS(a,j+k)],dp[POS(a,j)]+dp[POS(b,k)]);
      }
    }
  }
  int64 sum=0;
  for(i=1;i<=n;i++) sum+=dp[POS(i,1)];
  int m;
  scanf("%d",&m);
  int64 *t=(int64 *)calloc(m+1,sizeof(int64));
  for(i=1;i<=m;i++) scanf("%lld",t+i);
  qsort(t+1,m,sizeof(int64),cmpInt);
  t[0]=0;
  for(i=1;i<=m;i++) t[i]+=t[i-1];
  int64 max=sum;
  for(i=1;i<=m && i<=n;i++){
    max=MAX(max,sum-dp[POS(1,i)]+t[i]);
  }
  printf("%lld\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:32:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%lld",dp+POS(i,1));
                     ^
./Main.c:34:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n-1;i++) scanf("%d%d",&e[i].a,&e[i].b);
                      ^
./Main.c:52:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m);
   ^
./Main.c:54:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=m;i++) scanf("%lld",t+i);
                     ^