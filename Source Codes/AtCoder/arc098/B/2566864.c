#include<stdio.h>
int main(){
  long long n,d[200010],l=0,r=0,ans=0,x=0,i,s[200010]={};
  scanf("%lld",&n);
  for(i=0;i<n;i++)scanf("%lld",&d[i]);
  for(i=0;i<n;i++)s[i+1]=s[i]+d[i];
  //for(i=0;i<=n;i++)printf("%lld ",s[i]);printf("\n");
  for(l=0;l<n;l++){
    while((s[r]-s[l])==x&&r<=n)x^=d[r++];//printf("!%lld %lld\n",l,r);
    if(s[r-1]-s[l]==x^d[r-1])ans+=(r-l-1);
    //printf("%lld %lld %lld\n",ans,x^d[r-1],s[r-1]-s[l]);
    x^=d[l];
    //l++;    
    //while((s[r]-s[l])==x&&l<n)x^=d[l++];printf("%lld %lld\n",l,r);
  }
  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^
./Main.c:5:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%lld",&d[i]);
                   ^