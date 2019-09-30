#include <stdio.h>

int main(void)
{int n;
 scanf("%d",&n);
 if(n<=999){printf("ABC");}
 else{printf("ABD");}
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^