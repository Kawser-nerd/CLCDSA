#include<stdio.h>
int main(){
  long long h,w;
  scanf("%lld %lld",&h,&w);
  if     (h==1&&w==1)printf("1\n");
  else if(h==1||w==1)printf("%lld\n",h+w-3);
  else               printf("%lld\n",(h-2)*(w-2));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&h,&w);
   ^