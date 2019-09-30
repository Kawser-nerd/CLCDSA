#include <stdio.h>

int main(void)
{

        int a,b,c,s;

        scanf("%d%d",&a,&b);

        if ((a<1)||(b<1)||(a>20)||(b>20)){
                return 1;
                }
        c=b%a;
        if(c==0){
        s=a+b;
        }
        else s=b-a;

        printf("%d",s);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a,&b);
         ^