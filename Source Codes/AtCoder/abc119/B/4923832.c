#include<stdio.h>

int main(void)
{
        int n, i;
        double x, r=0;
        char v[4];

        scanf("%d", &n);

        for(i = 0; i < n; i++) {
                scanf("%lf%s", &x,&v);
                if(strcmp(v ,"JPY") == 0) {
                        r += x;
                } else {
                        r += x*380000;
                }
        }
        printf("%lf",r);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:23: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[4]’ [-Wformat=]
                 scanf("%lf%s", &x,&v);
                       ^
./Main.c:13:20: warning: implicit declaration of function ‘strcmp’ [-Wimplicit-function-declaration]
                 if(strcmp(v ,"JPY") == 0) {
                    ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &n);
         ^
./Main.c:12:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%lf%s", &x,&v);
                 ^