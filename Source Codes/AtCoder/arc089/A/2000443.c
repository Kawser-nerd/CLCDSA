#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
  int n, t, x, y, tn=0, xn=0, yn=0, d, i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d %d",&t,&x,&y);
    d = t-tn-abs(x-xn)-abs(y-yn);
    if(d<0 || d%2!=0) break;
    xn=x;  yn=y; tn=t;
  }
  if(i==n) printf("Yes\n");
  else printf("No\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&t,&x,&y);
     ^