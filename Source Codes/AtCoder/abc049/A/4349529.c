#include <stdio.h>
int main(void)
{
    char c[10];

    scanf("%s", c);

    if(c[0]=='a' || c[0]=='i' || c[0]=='u' || c[0]=='e' || c[0]=='o')
        printf("vowel\n");
    else
        printf("consonant\n");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", c);
     ^