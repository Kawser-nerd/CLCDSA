#include<stdio.h>
long long MAX(long long a,long long b){return a<b?b:a;}
int main(){
  long long n,m,max=0,a[100010],b[100010],i,d[4][100010]={};
  scanf("%lld %lld",&n,&m);
  for(i=0;i<n;i++)scanf("%lld %lld",&a[i],&b[i]);
  for(i=0;i<n;i++)d[0][i+1]=d[0][i]+b[i];
  for(i=0;i<n;i++)d[1][i+1]=MAX(d[1][i],d[0][i+1]-a[i]*2);
  for(i=0;i<n;i++)d[0][i+1]=MAX(d[0][i],d[0][i+1]-a[i]  );
  //for(i=0;i<=n;i++)printf("%lld %lld\n",d[0][i],d[1][i]);//printf("\n");
  //for(i=0;i<=n;i++)printf("%lld\n",d[0][i]);printf("\n%lld %lld\n",max0,max1);
  for(i=n;i  ;i--)d[2][i-1]=d[2][i]+b[i-1];
  //for(i=0;i<=n;i++)printf("%lld\n",d[2][i]);printf("\n");
  for(i=n;i  ;i--)d[3][i-1]=MAX(d[3][i],d[2][i-1]-(m-a[i-1])*2);
  for(i=n;i  ;i--)d[2][i-1]=MAX(d[2][i],d[2][i-1]-(m-a[i-1])  );
  //for(i=0;i<=n;i++)printf("%lld %lld %lld %lld\n",d[0][i],d[1][i],d[2][i],d[3][i]);
  for(i=0;i<=n;i++)max=MAX(max,MAX(d[0][i]+d[3][i],d[1][i]+d[2][i]));
  printf("%lld\n",max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&n,&m);
   ^
./Main.c:6:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%lld %lld",&a[i],&b[i]);
                   ^