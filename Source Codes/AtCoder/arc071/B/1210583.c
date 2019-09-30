#include<stdio.h>
int main(){
  long long s=0,i,j,h,w,n,m,x[100010],y[100010],M=1e9+7,a,b,l=0;
  scanf("%lld %lld",&n,&m);
  for(i=0;i<n;i++)scanf("%lld",&x[i]);
  for(j=0;j<m;j++)scanf("%lld",&y[j]);
  h=(y[m-1]-y[0])%M;
  w=(x[n-1]-x[0])%M;
  for(i=1;i<n;i++){
    a=(x[i]-x[i-1])%M;
    b=(i*(n-i))%M;
    l=(l+(a*b)%M)%M;
  }
  for(i=1;i<m;i++){
    a=(y[i]-y[i-1])%M;
    b=(i*(m-i))%M;
    s=(s+(l*(a*b%M)%M))%M;
  }
  printf("%lld\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&n,&m);
   ^
./Main.c:5:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%lld",&x[i]);
                   ^
./Main.c:6:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(j=0;j<m;j++)scanf("%lld",&y[j]);
                   ^