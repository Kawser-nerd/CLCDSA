#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int cnt[10]={9,2,5,5,4,5,6,3,7,6};
  int use[10]={0};
  while(m--){
    int a;
    scanf("%d",&a);
    use[a]=1;
  }
  int *dp=(int *)calloc(n+1+6,sizeof(int));
  const int ini=-1;
  int i,j;
  for(i=1;i<=n;i++) dp[i]=ini;
  for(i=0;i<n;i++){
    if(dp[i]==ini) continue;
    for(j=1;j<=9;j++){
      if(use[j]==0) continue;
      int c=cnt[j];
      dp[i+c]=MAX(dp[i+c],dp[i]+1);
    }
  }
  int ans[10]={0};
  i=n;
  while(i>0){
    for(j=9;j>=1;j--){
      int c=cnt[j];
      if(use[j]==0 || i-c<0) continue;
      if(dp[i-c]==dp[i]-1){
	ans[j]++;
	i-=c;
	break;
      }
    }
  }
  for(i=9;i>=1;i--){
    while(ans[i]--) putchar('0'+i);
  }
  puts("");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^