#include <stdio.h>
int main(void)
{
    int a, b, i;

    scanf("%d%d", &a, &b);

    if(a<=0 && b>=0){
        printf("Zero\n");
        return 0;
    }

    if(a>0 && b>0) printf("Positive\n");
    else if((a-b+1)%2==0) printf("Positive\n");
    else printf("Negative\n");
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a, &b);
     ^