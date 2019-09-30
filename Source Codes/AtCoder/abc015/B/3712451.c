#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(void) {
  double n,x,sum=0,cnt=0;
  scanf("%lf",&n);
  for(int i=0; i<n; i++) {
    scanf("%lf",&x);
    if(x!=0) {
      sum+=x;
      cnt++;
    }
  }
  printf("%.lf\n",ceil(sum/cnt));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf",&n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf",&x);
     ^