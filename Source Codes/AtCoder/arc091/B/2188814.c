#include<stdio.h>
int main(){
  long long s=0,n,i,k,a,b,c;
  scanf("%lld %lld",&n,&k);
  if(k==0){
    printf("%lld\n",n*n);
    return 0;
  }
  for(i=k+1;i<=n;i++){
    a=i-k;
    b=(n+1)/i;
    c=b*i;
    c=n-c-k+1;
    s+=a*b;
    if(c>0)s+=c;
    //printf("%lld %lld %lld %lld\n",i,a,b,c);
  }
  printf("%lld\n",s);   
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&n,&k);
   ^