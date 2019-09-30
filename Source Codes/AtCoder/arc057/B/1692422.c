#include<stdio.h>
long long MIN(long long a,long long b){return a<b?a:b;}
long long MAX(long long a,long long b){return a<b?b:a;}
long long k,a,b,d[2010][2010],e[2010][2010],s[2010]={};
int main(){
  int n,i,j,max=0;
  scanf("%d %lld",&n,&k);
  for(i=0;i<2005*2005;i++)d[i/2005][i%2005]=1e18;
  d[0][0]=s[0]=0;
  for(i=0;i<n;i++){
    scanf("%lld",&a);
    s[i+1]=s[i]+a;//printf("%2lld:",s[i]);
    for(j=0;j<=i;j++){//printf("%lld ",e[i][j]);
      if(d[i][j]>k)break;
      d[i+1][j]=MIN(d[i][j],d[i+1][j]);
      b=i?(d[i][j]*s[i+1])/s[i]+1:1;
      if(b<=a+d[i][j]&&b<=k)d[i+1][j+1]=MIN(d[i+1][j+1],b);
    }//printf("\n");
  }
  for(i=0;i<=n;i++){
    if(d[n][i]<=k)max=i;
  }
  printf("%d\n",s[n]-k?max:1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %lld",&n,&k);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&a);
     ^