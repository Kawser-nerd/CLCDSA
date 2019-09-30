#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define M 18

#define POS(i,j) ((i)*M+(j))

void run(void){
  int n;
  scanf("%d",&n);
  int *x=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",x+i);
  int l;
  scanf("%d",&l);
  int *dp=(int *)malloc(sizeof(int)*n*M);
  int r=0;
  for(i=0;i<n;i++){
    while(r<n && x[r]-x[i]<=l) r++;
    dp[POS(i,0)]=r-1;
  }
  for(i=0;dp[POS(0,i)]<n-1;i++){
    int j;
    for(j=0;j<n;j++){
      dp[POS(j,i+1)]=dp[POS(dp[POS(j,i)],i)];
    }
  }
  int q;
  scanf("%d",&q);
  while(q--){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;
    b--;
    if(a>b){
      int c=a;
      a=b;
      b=c;
    }
    int ans=0;
    int now=a;
    while(now<b){
      int i=0;
      while(dp[POS(now,i)]<b) i++;
      if(i==0){
	ans++;
	break;
      }
      i--;
      ans+=(1<<i);
      now=dp[POS(now,i)];
    }
    printf("%d\n",ans);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:20:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",x+i);
                    ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&l);
   ^
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^