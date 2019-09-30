#include<stdio.h>
#include<string.h>
char s[1001];
int main ()
{
    char x; 
    scanf("%c",&x);
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {if(s[i]==x)
    continue;   
    else
    printf("%c",s[i]);}
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&x);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^