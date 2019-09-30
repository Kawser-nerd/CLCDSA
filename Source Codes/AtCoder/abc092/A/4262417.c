#include <stdio.h>

int main(void)
{int a,b,c,d;
 scanf("%d%d%d%d",&a,&b,&c,&d);
 int sum=0;
 if(a>=b){sum+=b;}else{sum+=a;}
 if(c>=d){sum+=d;}else{sum+=c;}
 printf("%d",sum);
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&a,&b,&c,&d);
  ^