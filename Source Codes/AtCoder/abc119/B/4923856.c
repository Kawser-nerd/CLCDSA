#include<stdio.h>

#define BTC2YEN 380000.0

int main(void)
{
    int n;
    scanf("%d",&n);

    int i;
    double yen = 0.0;
    for(i=0;i<n;i++){
        double money;
        char type[3];
        scanf("%lf%s", &money, &type);
        if (type[0] == 'B')
            yen += money * BTC2YEN;
        else
            yen += money;
    }

    printf("%lf", yen);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:15: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[3]’ [-Wformat=]
         scanf("%lf%s", &money, &type);
               ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf%s", &money, &type);
         ^