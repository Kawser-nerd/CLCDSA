#include<stdio.h>
#include<math.h>
int main(void){
  unsigned long long a=0,b=0,c=0,ans;
  scanf("%llu%llu%llu",&a,&b,&c);
  ans=(a*b<b*c)?(a*b<a*c)?a*b:a*c:(b*c<a*c)?b*c:a*c;
  if(a%2*b%2*c%2)printf("%llu",ans);
  else puts("0");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu%llu%llu",&a,&b,&c);
   ^