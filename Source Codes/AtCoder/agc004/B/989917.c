#include<stdio.h>
long long  MIN(long long a,long long b){return a<b?a:b;}
int main(){
  long long n,m,a[2010],b[2010],min=1e18,s,i,j;
  scanf("%lld %lld",&n,&m);//printf("%lld\n",min);
  for(i=0;i<n;i++)scanf("%lld",&a[i]);
  for(i=0;i<n;i++)b[i]=1e9;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)b[j]=MIN(b[j],a[(j-i+n)%n]);
    for(j=s=0;j<n;j++)s+=b[j];
    min=MIN(min,s+m*i);
  }
  printf("%lld\n",min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&n,&m);//printf("%lld\n",min);
   ^
./Main.c:6:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%lld",&a[i]);
                   ^