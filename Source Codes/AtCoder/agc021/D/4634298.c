#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define POS(cnt,LEN,L) ((((cnt)&1)*(n+1)+(LEN))*(n+1)+(L))

void run(void){
  char *s=(char *)calloc(301,sizeof(char));
  scanf("%s",s);
  const int n=strlen(s);
  int k;
  scanf("%d",&k);
  int *dp=(int *)calloc((n+1)*(n+1)*2,sizeof(int));
  for(int cnt=0;cnt<=k;cnt++){
    memset(dp+POS(cnt,0,0),0,sizeof(int)*(n+1)*(n+1));
    for(int l=0;l<n;l++){
      dp[POS(cnt,1,l)]=1;
    }
    for(int len=2;len<=n;len++){
      for(int l=0;l+len<=n;l++){
	if(s[l]==s[l+len-1]){
	  dp[POS(cnt,len,l)]=dp[POS(cnt,len-2,l+1)]+2;
	} else {
	  int a=cnt>0?dp[POS(cnt-1,len-2,l+1)]+2:0;
	  int b=dp[POS(cnt,len-1,l)];
	  int c=dp[POS(cnt,len-1,l+1)];
	  dp[POS(cnt,len,l)]=MAX(a,MAX(b,c));
	}
      }
    }
  }
  printf("%d\n",dp[POS(k,n,0)]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^