#include<stdio.h>
int main(){
  long long n,i,a,b,p,d[100010];
  scanf("%lld",&n);
  for(i=0;i<n;i++)scanf("%lld",&d[i]);
  a=b=2;
  d[n]=1e9;
  if(d[n-1]-2)goto END;
  for(i=n;i--;){
    if(a%d[i])a+=d[i]-a%d[i];
    b+=d[i]-b%d[i]-1;
  }
  p=a;
  for(i=0;i<n;i++)p-=p%d[i];
  if(p-2)goto END;
  p=b;
  for(i=0;i<n;i++)p-=p%d[i];
  if(p-2)goto END;
  printf("%lld %lld\n",a,b);
  return 0;
 END:;
  printf("-1\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^
./Main.c:5:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%lld",&d[i]);
                   ^