#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define POS(cnt,L,R) (((cnt)*(n+1)+(L))*(n+1)+(R))

void run(void){
  char *s=(char *)calloc(301,sizeof(char));
  scanf("%s",s);
  const int n=strlen(s);
  int k;
  scanf("%d",&k);
  int *dp=(int *)calloc((n+1)*(n+1)*(k+1),sizeof(int));
  for(int cnt=0;cnt<=k;cnt++){
    for(int l=0;l<n;l++){
      dp[POS(cnt,l,l+1)]=1;
    }
    for(int len=2;len<=n;len++){
      for(int l=0;l+len<=n;l++){
	if(s[l]==s[l+len-1]){
	  dp[POS(cnt,l,l+len)]=dp[POS(cnt,l+1,l+len-1)]+2;
	} else {
	  int a=cnt>0?dp[POS(cnt-1,l+1,l+len-1)]+2:0;
	  int b=dp[POS(cnt,l+1,l+len)];
	  int c=dp[POS(cnt,l,l+len-1)];
	  dp[POS(cnt,l,l+len)]=MAX(a,MAX(b,c));
	}
      }
    }
  }
  printf("%d\n",dp[POS(k,0,n)]);
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