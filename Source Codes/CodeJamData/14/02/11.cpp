#include <cstdio>
#include <algorithm>

double C, F, X;

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        scanf("%lf%lf%lf", &C, &F, &X);
        double res = X/2;
        double now = 0;
        for(int farms=0; now<res; farms++)
        {
            now+=C/(2+farms*F);
            res=std::min(res, now+X/(2+(farms+1)*F));
        }
        printf("Case #%d: %.7f\n", t, res);
    }
    return 0;
}
