#include<cstdio>
#define Min(a, b) ((a)<(b))?(a):(b)
const int inf = 0x3f3f3f;
using namespace std;
int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        int i, a, b, c, d, e, m, l;
        int minx = inf;
        if(n < 10)
            printf("%d\n", n);
        else if(n == 10)
            printf("10\n");
        else if(n<20)
        {
            for(i=10; i<=n; i++)
            {
                a = i%10;
                l = a+1;
                m = n-i;
                l += m;
                minx = Min(l, minx);
            }
            printf("%d\n", l);
        }
        else if(n>=20)
        {
            for(i=n-1; i>=n/2; i--)
            {
                m = n-i;
                a = m % 10;
                b = (m-a)/10%10;
                c = (m-b*10-a)/100%10;
                d = (m-c*100-b*10-a)/1000%10;
                e = m/10000;
                l = a+b+c+d+e;
                a = i % 10;
                b = (i-a)/10%10;
                c = (i-b*10-a)/100%10;
                d = (i-c*100-b*10-a)/1000%10;
                e = i/10000;
                l += a+b+c+d+e;
                minx = Min(minx, l);
            }
            printf("%d\n", minx);
        }
    }
}