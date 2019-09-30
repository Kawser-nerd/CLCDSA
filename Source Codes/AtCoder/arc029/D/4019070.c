#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))

int cmp(const void *a,const void *b){
  return *(int *)b-*(int *)a;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *s=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",s+i);
  int *a=(int *)calloc(n-1,sizeof(int));
  int *b=(int *)calloc(n-1,sizeof(int));
  for(i=0;i<n-1;i++){
    scanf("%d%d",a+i,b+i);
    a[i]--;
    b[i]--;
  }
  int64 **dp=(int64 **)calloc(n,sizeof(int64 *));
  int *size=(int *)calloc(n,sizeof(int));
  int *child=(int *)calloc(n,sizeof(int));
  for(i=n-1;i>=0;i--){
    int len=0;
    int j;
    for(j=0;j<n-1;j++) if(a[j]==i) child[len++]=b[j];
    int num=1;
    int64 sum=s[i];
    for(j=0;j<len;j++){
      int v=child[j];
      num+=size[v];
      sum+=dp[v][0];
    }
    size[i]=num;
    dp[i]=(int64 *)calloc(num+1,sizeof(int64));
    dp[i][0]=sum;
    int k=1;
    for(j=0;j<len;j++){
      int v=child[j];
      int f,l;
      for(f=k;f>=1;f--){
	for(l=size[v];l>=0;l--){
	  dp[i][f+l]=MAX(dp[i][f+l],dp[i][f]+dp[v][l]);
	}
      }
      k+=size[v];
      free(dp[v]);
    }
  }
  int m;
  scanf("%d",&m);
  int *t=(int *)calloc(m,sizeof(int));
  for(i=0;i<m;i++) scanf("%d",t+i);
  qsort(t,m,sizeof(int),cmp);
  int64 ans=dp[0][0];
  int64 sum=0;
  for(i=0;i<m && i+1<=size[0];i++){
    sum+=t[i];
    ans=MAX(ans,sum+dp[0][i+1]);
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:17:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",s+i);
                    ^
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",a+i,b+i);
     ^
./Main.c:56:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m);
   ^
./Main.c:58:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<m;i++) scanf("%d",t+i);
                    ^