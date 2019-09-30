#include <stdio.h>

int main(void)
{
    int A,B,C;
    scanf("%d",&A);
    if (A%100 < (A/100)*10+A/100){
        printf("%d",(A/100)*100+(A/100)*10+A/100);
    } else if (A%100 == (A/100)*10+A/100)
    {
        printf("%d",A);
    } else
    {
        printf("%d",(A/100+1)*100+(A/100+1)*10+A/100+1);
    }
    
    

} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^