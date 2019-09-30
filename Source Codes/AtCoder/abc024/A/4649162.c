#include <stdio.h>
int main(void){
    int a,b,c,k,s,t;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&k,&s,&t);
    printf("%d\n",s+t>=k?(a-c)*s+(b-c)*t:a*s+b*t);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d%d%d",&a,&b,&c,&k,&s,&t);
     ^