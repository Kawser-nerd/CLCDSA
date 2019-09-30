#include <stdio.h>
int main (void)
{
        int  a,b,c,d;
        int  k[100]={0};
        int  i,j=0;

        scanf("%d%d%d",&a,&b,&c);

        d=a;
        if (a>b) d=b;

        for(i=1;i<=d;i++){
        if ((a%i==0)&&(b%i==0)){k[j]=i;
        j++;}
        }

      printf("%d\n", k[j-c]);

        return 0;
        } ./Main.c: In function ‘main’:
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&a,&b,&c);
         ^