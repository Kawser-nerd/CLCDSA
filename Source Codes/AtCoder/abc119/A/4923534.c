#include<stdio.h>
#include<string.h>

int main(void)
{
    char c[11];

    scanf("%s",c);
    if  (strcmp(c,"2019/04/30")<=0)
         printf("Heisei\n");
    else printf("TBD\n");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",c);
     ^