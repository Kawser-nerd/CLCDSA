#include <stdio.h>
#include <string.h>
int main(void)
{
    int a,b;
    char op;
    scanf("%d %c %d", &a, &op, &b);
    if(strncmp(&op, "+", 1)==0) printf("%d", a+b);
    else printf("%d", a-b);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %c %d", &a, &op, &b);
     ^