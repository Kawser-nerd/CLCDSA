#include <cstdio>
int d,n;
int main()
{
    while (scanf("%d%d",&d,&n)!=EOF)
    {
        int t=1;
        for (int i=0;i<d;i++) t=t*100;
        if (d==0 && n==100) puts("101");
        else if (d==1 && n==100) puts("10100");
        else if (d==2 && n==100) puts("1010000");
        else printf("%d\n",t*n);
    }
    return 0;
}