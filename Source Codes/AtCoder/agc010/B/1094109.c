#include<stdio.h>
int main(){
  long long n,d[100010],s=0,m,i,p;
  scanf("%lld",&n);
  m=(n*(n+1))/2;
  for(i=0;i<n;i++){
    scanf("%lld",&d[i]);
    s+=d[i];
  }
  if(s%m)goto END;
  s/=m;//printf("%lld\n",s);
  p=d[0];
  for(i=1;i<n;i++)d[i-1]+=s-d[i];
  d[n-1]+=s-p;
  //for(i=0;i<n;i++)printf("%lld ",d[i]);printf("\n");
  for(i=0;i<n;i++){
    if(d[i]<0||d[i]%n)goto END;
  }
  printf("YES\n");
  return 0;
 END:;
  printf("NO\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&d[i]);
     ^