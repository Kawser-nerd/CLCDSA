#include <stdio.h>

int main(void)
{
        int n,a,b,i;

        scanf("%d",&n);

        a=n;

        if ((n%7==0)||(n%4==0)){
                printf("Yes\n");
                return 0;
        }

        else if (n<4){
                printf("No\n");
                return 0;
        }

        while(1){
                a=a-7;
                if (a%4==0){
                        printf("Yes\n");
                        return 0;
                }
                else if (a<4){
                        printf("No\n");
                        return 0;
                }
        }
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&n);
         ^