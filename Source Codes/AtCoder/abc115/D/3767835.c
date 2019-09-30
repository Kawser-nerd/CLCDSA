#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 1000000007

long long pan(long long n)
{
  //printf("pan called pan(%lld)\n",n);
  if(n<=1)
    return 1;
  else
    return 2*pan((n-3)/2) + 1;
}

long long barger(long long left, long long right, long long x)
{
  //printf("barger called: barger(%lld, %lld, %lld)\n",left,right,x);
  long long mid = (right+left)/2;
  if(left>=mid)
    return 1;
  else if(x==right && (right-left)>0)
    return 0;
  else if(x<mid)
    return barger(left+1, mid-1, x) + 1 + pan(right-mid-1);
  else if(x==mid)
    return 1 + pan(right-mid-1);
  else if(mid<x)
    return barger(mid+1, right-1, x);
}

int main(void)
{
  long long n, layer, x, ans;
  scanf("%lld %lld",&n,&x);
  layer = pow(2, n+2) - 3;
  x = layer-x+1;
  //printf("layer: %lld\n",layer);
  ans = barger(1, layer, x);
  printf("%lld",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&n,&x);
   ^