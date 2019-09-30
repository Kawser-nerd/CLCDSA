#include<stdio.h>
#include<string.h>

int main (void)
{
        int i, n, k;
        double m, x[100];
        char u[100][5];

        scanf("%d",&n);
        for(i=0;i<n;i++){
                scanf("%lf",&x[i]);
                scanf("%s",&u[i]);
        }
        k=0;
        for(i=0;i<n;i++){
                if(strcmp(u[i], "JPY")==0)
                        m=m+x[i];
                else if(strcmp(u[i], "BTC")==0)
                        m=m+x[i]*380000.0;
        }

        printf("%lf\n",m);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:23: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[5]’ [-Wformat=]
                 scanf("%s",&u[i]);
                       ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&n);
         ^
./Main.c:12:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%lf",&x[i]);
                 ^
./Main.c:13:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%s",&u[i]);
                 ^