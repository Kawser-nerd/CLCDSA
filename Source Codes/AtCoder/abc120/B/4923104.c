#include <stdio.h>

int main(void)
{
        int a, b, c, n[100]={}, k, i, j=0;

        scanf("%d%d%d", &a, &b, &k);
        if(a<b) c=b;
        else c=a;
        for(i=c;i>0;i--)
                if((a%i==0)&&(b%i==0)) {
                        n[j] = i;
                        j++;
        }
        printf("%d\n",n[k-1]);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d", &a, &b, &k);
         ^