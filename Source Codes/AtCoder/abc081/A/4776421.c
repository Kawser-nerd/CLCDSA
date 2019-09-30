#include <stdio.h>

int main(void)
{
    char s[3];
    scanf("%s",s);
    
    int i,j=0;
    
    for (i=0;i<3;i++) {
        if (s[i] == '1') j++;
    }
    
    
    printf("%d\n",j);
    
    return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^