#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  long int  n,k,t,min,max,s;
  scanf("%ld %ld %ld",&n,&k,&t);
  if(k>t||n<1||(n==1&&k!=t))
  {
    printf("0\n");
  }

else
{
   max=(n-1)*t+k;
  min =(n-1)*k+t;
  s=max-min+1;
  printf("%ld\n",s);
   
}
 return 0;

} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld %ld",&n,&k,&t);
   ^