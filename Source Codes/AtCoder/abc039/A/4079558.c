#include <stdio.h>
int main(){
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      printf("%d",2*a*b+2*c*b+2*a*c);
      return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d%d",&a,&b,&c);
       ^