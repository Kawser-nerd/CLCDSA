#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    scanf("%s",a);
    
    if (strcmp(a,"2019/04/30")<=0)
        printf("Heisei\n");
    else
        printf("TBD\n");
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",a);
     ^