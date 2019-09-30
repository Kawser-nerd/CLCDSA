#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(void){
  int n,i,j,ans=0;
  scanf("%d",&n);
  for(i=1;i<=n;i+=2){
    int cnt=0;
    for(j=1;j<=i;j++){
      if(i%j==0) cnt++;
    }
    if(cnt==8)ans++;
  }
  printf("%d",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^