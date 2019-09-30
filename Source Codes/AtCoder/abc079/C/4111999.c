#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int a[4],b[3],i,m[3];
    char num[5];
    scanf("%s",num);
    for (i=0;i<4;i++)
    {
        a[i]=num[i]-'0';
    }
    for (i=0;i<8;i++)
    {
        m[0]=i%2;
        m[1]=i/2%2;
        m[2]=i/4%2;
        b[0]=pow(-1,m[0])*a[1];
        b[1]=pow(-1,m[1])*a[2];
        b[2]=pow(-1,m[2])*a[3];
        if (a[0]+b[0]+b[1]+b[2]==7) break;
    }
    printf("%d",a[0]);
    for (i=0;i<3;i++)
    {
        if (m[i]) printf("-");
        else printf("+");
        printf("%d",a[i+1]);
    }
    printf("=7");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",num);
     ^