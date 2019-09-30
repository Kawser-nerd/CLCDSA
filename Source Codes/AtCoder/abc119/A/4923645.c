#include<stdio.h>

int main(void)
{
        char s[100];

        scanf("%s", s);
        if(strcmp(s, "2019/04/30") <= 0) {
                printf("Heisei");
        } else {
                printf("TBD");
        }
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:12: warning: implicit declaration of function ‘strcmp’ [-Wimplicit-function-declaration]
         if(strcmp(s, "2019/04/30") <= 0) {
            ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", s);
         ^