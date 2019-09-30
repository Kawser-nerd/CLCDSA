#include <stdio.h>

int main(void)
{
        int n,a,i,j,s=0;

        scanf("%d",&n);

        //if (n>200)    return 1;

        for(i=1;i<=n;i++){
                a=0;
                for (j=1; j<=i;j++){
                        if ((i%2==1)&&(i%j==0))
                                a++;
                }
                if(a==8)
                        s++;
        }

        printf("%d\n",s);

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&n);
         ^