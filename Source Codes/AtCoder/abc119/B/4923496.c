#include<stdio.h>
#include<string.h>
int main(void)
{

        char a[4];

        char *bt = "BTC";

        char *jp = "JPY";

        double b,s;

        int i,c;

        scanf("%d",&c);

        for(i=0;i<c;i++){

                scanf("%lf%s",&b,a);

                if(strcmp(a,jp)==0){

                        s+=b;
                }

                if(strcmp(a,bt)==0){

                        s+=(380000*b);
                }

        }

        printf("%f\n",s);

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&c);
         ^
./Main.c:20:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%lf%s",&b,a);
                 ^