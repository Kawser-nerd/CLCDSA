#include <stdio.h>
int main(void){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%d\n",(a>=d || b<=c)?0:(a>c?(b-a>d-a?d-a:b-a):(b-c>d-c?d-c:b-c)));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&a,&b,&c,&d);
     ^