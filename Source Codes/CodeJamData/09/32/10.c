#include <stdio.h>
#include <math.h>
typedef long long int int64;

int main()
{
    int64 t;
    scanf("%lld", &t);
    int64 Case=0;
    for (Case=0;Case<t;Case++)
    {
        int64 n;
        scanf("%lld", &n);
        int64 subc = 0;
        int64 a =0 ,b=0,c=0,aprime=0,bprime=0,cprime=0;
        for (subc =0;subc<n;subc++)
        {
            int64 x,y,z,vx,vy,vz;
            scanf("%lld %lld %lld %lld %lld %lld", &x, &y, &z, &vx, &vy, &vz);
            a += x;
            b += y;
            c += z;
            aprime += vx;
            bprime += vy;
            cprime += vz;
        //printf("%d %d %d %d %d %d\n", x, y, z, vx, vy, vz);
        }
        int64 num = a*aprime + b*bprime + c*cprime;
        long double den = pow(aprime, 2) + pow(bprime, 2) + pow(cprime, 2);
        long double time;
        if (den == 0)
            time = 0;
        else
            time = (-1)*num/den;
        if (time <=(long double)0)
            time = (long double)0;

        long double mx = a + time*aprime;
        long double my = b+ time*bprime;
        long double mz = c + time*cprime;

        long double d = (sqrt(pow(mx, 2)+pow(my, 2)+pow(mz,2)))/n;
        printf ("Case #%lld: %.8Lf %.8Lf\n", Case+1, d, time);
    }
return 0;
}

