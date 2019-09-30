#include<stdio.h>
int main(void){int a,b,c;scanf("%d%d%d",&a,&b,&c);if(c==a+b){if(c!=a-b)printf("+\n");else printf("?\n");}else if(c==a-b)printf("-\n");else printf("!\n");return 0;} ./Main.c: In function ‘main’:
./Main.c:2:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int main(void){int a,b,c;scanf("%d%d%d",&a,&b,&c);if(c==a+b){if(c!=a-b)printf("+\n");else printf("?\n");}else if(c==a-b)printf("-\n");else printf("!\n");return 0;}
                          ^