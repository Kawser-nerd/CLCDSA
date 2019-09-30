#include <stdio.h>
#include <string.h>

int main(void)
{
        int a;
        char s[10], t[10] = "2019/04/30";

        scanf("%s", s);

        a = strcmp(s, t);

        if(a<0) printf("Heisei\n");
        else printf("TBD\n");

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", s);
         ^