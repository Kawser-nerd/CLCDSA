#include<stdio.h>

int main (void)
{
        int a, b, k, m[100], i, d, s;

        scanf("%d%d%d",&a,&b,&k);
        d = 0;
        if(a<b)s=a;
        else   s=b;
        for(i=s;i>0;i--){
                if((a%i==0)&&(b%i==0)){
                        m[d]=i;
                        d=d+1;
                }
        }
        printf("%d\n",m[k-1]);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&a,&b,&k);
         ^