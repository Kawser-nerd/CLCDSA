#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
  int k, i;
  unsigned long long int a[100000], max=2, min=2;
  scanf("%d",&k);
  for(i=0;i<k;i++) scanf("%lld",&a[i]);
  for(i=0;i<k;i++){
    if(max<a[k-i-1]) break;
    if(max-max%a[k-i-1]<min) break;
    max=max-max%a[k-i-1]+a[k-i-1]-1;
    if(min<a[k-i-1]) min=a[k-i-1];
    else if(min%a[k-i-1]!=0) min=min-min%a[k-i-1]+a[k-i-1];
    //printf("%d,%d...",min,max);
  }
  if(i!=k || a[k-1]!=2) printf("-1\n");
  else printf("%lld %lld\n",min, max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^
./Main.c:10:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<k;i++) scanf("%lld",&a[i]);
                    ^