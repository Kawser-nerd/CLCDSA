#include <stdio.h>
int main(void){
    int a,b;
    char s[2];
    scanf("%d%s%d",&a,s,&b);
    printf("%d\n",s[0]=='+'?a+b:a-b);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%s%d",&a,s,&b);
     ^