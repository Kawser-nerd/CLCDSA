#include<stdio.h>
int main()
{
    char s;
    scanf("%c", &s);
    if (s == 'L')printf("<");
    else if (s == 'R')printf(">");
    else if (s == 'A')printf("A");
    scanf("%c", &s);
    while (s != '\n')
    {
        if (s == 'L')printf(" <");
        else if (s == 'R')printf(" >");
        else if (s == 'A')printf(" A");
        scanf("%c", &s);
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c", &s);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c", &s);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%c", &s);
         ^