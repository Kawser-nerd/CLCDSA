#include <stdio.h>

int main()
{
    int A,B,C;
    scanf("%d%d%d",&A,&B,&C);
    
    if (B/A >= C) printf("%d\n",C);
    else printf("%d\n",B/A);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&A,&B,&C);
     ^