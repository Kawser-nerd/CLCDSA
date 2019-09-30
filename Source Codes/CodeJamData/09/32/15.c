#include <stdio.h>

long long x, y, z, vx, vy, vz;
int N;

void input(void)
{
    int tx, ty, tz, tvx, tvy, tvz;
    int i;
    
    x=y=z=vx=vy=vz = 0;
    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        scanf("%d %d %d %d %d %d", &tx, &ty, &tz, &tvx, &tvy, &tvz);
        x += tx;
        y += ty;
        z += tz;
        vx += tvx;
        vy += tvy;
        vz += tvz;
    }
}

/**
* Find the minimum of d(t)=sqrt(at^2+bt+c) for t>=0, where:
* a = (vx^2 + vy^2 + vz^2) / N^2
* b = 2 * (vx*x + vy*y + vz*z) / N^2
* c = (x^2 + y^2 + z^2) / N^2
*/
double solve(double *t)
{
    double a;
    double b;
    double c;
    double d2;
    
    a = (vx*vx + vy*vy + vz*vz) / (double)(N*N);
    c = (x*x + y*y + z*z) / (double)(N*N);
    if(vx*vx + vy*vy + vz*vz == 0)
    {
        /* In this case a==b==0 */
        *t = 0;
        return sqrt(c);
    }
    b = 2.0 * (vx*x + vy*y + vz*z) / (double)(N*N);
    *t = -b/(2.0*a);
    if(*t <= 0)
    {
        *t = 0;
    }
    d2 = a*(*t)*(*t) + b*(*t) + c;
    if(d2 <= 0)
    {
        /* d^2 must be very close to 0 */
        return 0;
    }
    return sqrt(d2);
}

int main(void)
{
    int T, test;
    double time, dist;
    
    scanf("%d", &T);
    for(test=1; test<=T; ++test)
    {
        input();
        dist = solve(&time);
        printf("Case #%d: %.8lf %.8lf\n", test, dist, time);
    }
    return 0;
}
