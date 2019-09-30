#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  int s[10]={0};
  s[a]++;s[b]++;s[c]++;
  if(s[5]==2&&s[7]==1) printf("YES");
  else printf("NO");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^