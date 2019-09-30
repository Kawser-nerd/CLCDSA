#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

const int mod=1000000007;
int modPow(int r,int n){
  int t=1;
  int s=r;
  while(n>0){
    if(n&0x01) t=(int64)t*s%mod;
    s=(int64)s*s%mod;
    n>>=1;
  }
  return t;
}

int *dp=NULL;
int calc(char *t,char *s,int n){
  int *dp2=dp+2*(n+1);
  int *dp1=dp+1*(n+1);
  int *dp0=dp+0*(n+1);
  int i;
  for(i=0;i<=n;i++){
    dp2[i]=dp1[i]=dp0[i]=0;
  }
  for(i=n-1;i>=0;i--){
    dp2[i]=dp2[i+1];
    if(s[i]==t[2]) dp2[i]++;
  }
  for(i=n-1;i>=0;i--){
    dp1[i]=dp1[i+1];
    if(s[i]==t[1]){
      dp1[i]+=dp2[i+1];
      dp1[i]%=mod;
    }
  }
  for(i=n-1;i>=0;i--){
    dp0[i]=dp0[i+1];
    if(s[i]==t[0]){
      dp0[i]+=dp1[i+1];
      dp0[i]%=mod;
    }      
  }
  return dp0[0];
}

void run(void){
  char *s=(char *)malloc(sizeof(char)*(100000+1));
  scanf("%s",s);
  int n=0;
  while(s[n]!='\0') n++;
  dp=(int *)malloc(sizeof(int)*3*(n+1));
  int cnt=0;
  int i;
  for(i=0;i<n;i++) if(s[i]=='?') cnt++;
  int64 ans=0;
  ans+=(int64)calc("ABC",s,n)*modPow(3,cnt);
  ans+=(int64)calc("AB?",s,n)*modPow(3,cnt-1);
  ans+=(int64)calc("A?C",s,n)*modPow(3,cnt-1);
  ans+=(int64)calc("?BC",s,n)*modPow(3,cnt-1);
  ans+=(int64)calc("A??",s,n)*modPow(3,cnt-2);
  ans+=(int64)calc("?B?",s,n)*modPow(3,cnt-2);
  ans+=(int64)calc("??C",s,n)*modPow(3,cnt-2);
  ans+=(int64)calc("???",s,n)*modPow(3,cnt-3);
  printf("%lld\n",ans%mod);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:55:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^