#include<stdio.h>
#include<math.h>

long long int min(long long int a,long long int b){
  if(a>b) return b;
  return a;
}

int main(void){
  long long int a,b,c,tmp;
  scanf("%lld %lld %lld",&a,&b,&c);
  tmp = min(a+b,c);
  if((a+b)<c) tmp++;
  printf("%lld\n",tmp+b);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld",&a,&b,&c);
   ^