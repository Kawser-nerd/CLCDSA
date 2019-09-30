#include <stdio.h>
#include <string.h>
int main()
{   char a[101],b[101];
    scanf("%s%s",a,b);
        if(strlen(a)>strlen(b)){
            printf("GREATER");
            return 0;
        }
        if(strlen(b)>strlen(a)){
            printf("LESS");
            return 0;
        }
    int c=strcmp(a,b);
    if(c>0)printf("GREATER");
    else if(c<0)printf("LESS");
    else printf("EQUAL");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s",a,b);
     ^