#include <stdio.h>
int main(void){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(b-a<=0)
    {
        printf("delicious");
        return 0;
    }
    if(n>=b-a)
    {
        printf("safe");
        return 0;
    }
    if(b-a>n)
    {
        printf("dangerous");
        return 0;
    }
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&a,&b);
     ^