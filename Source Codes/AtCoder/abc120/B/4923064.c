#include<stdio.h>

int main(void)
{

        int a, b, k, s, i;

        scanf("%d%d%d", &a, &b, &k);

        for(i=100; i>=1; i--){
                if((a%i==0) && (b%i==0))
                        s++;
                if(s==k) break;
        }
        printf("%d\n", i);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d", &a, &b, &k);
         ^