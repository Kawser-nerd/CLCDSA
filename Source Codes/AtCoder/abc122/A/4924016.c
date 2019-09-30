#include <stdio.h>

int main()
{
    char a[1];
    
    scanf("%s",a);
    
    if (a[0] == 'A') printf("T\n");
    if (a[0] == 'T') printf("A\n");
    if (a[0] == 'G') printf("C\n");
    if (a[0] == 'C') printf("G\n");
    
    return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",a);
     ^