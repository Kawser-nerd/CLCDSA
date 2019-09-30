#include <stdio.h>
int main(){
  long int a,b,c,ans;
  scanf("%ld%ld%ld",&a,&b,&c);
  ans=a+2*b+1;
  if(b+c<ans)ans=b+c;
  printf("%ld",ans);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld%ld",&a,&b,&c);
   ^