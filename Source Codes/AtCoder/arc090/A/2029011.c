#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
  int n, a[2][100], i, j, d=0, maxd=0, max=0, ans=0;
  scanf("%d",&n);
  for(i=0;i<2;i++) for(j=0;j<n;j++) scanf("%d",&a[i][j]);
  for(i=0;i<n-1;i++){
    d+=a[1][n-2-i]-a[0][n-1-i];
    if(maxd<d){max=i; maxd=d;}
  }
  max = n-2-max;  if(max<0) max=0;
  //printf("max: %d...",max);
  for(i=0;i<n;i++){
    if(i<=max) ans+=a[0][i];
    if(i>=max) ans+=a[1][i];
  }
  printf("%d\n",ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:9:37: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<2;i++) for(j=0;j<n;j++) scanf("%d",&a[i][j]);
                                     ^