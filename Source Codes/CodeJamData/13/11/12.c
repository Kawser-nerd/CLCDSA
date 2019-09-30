#include <stdio.h>
#include <limits.h>

unsigned long long times(unsigned long long x, unsigned long long y)
{
    if(ULLONG_MAX/x<y) {
        return ULLONG_MAX;
    } else {
        return x*y;
    }
}

unsigned long long add(unsigned long long x, unsigned long long y)
{
    if(ULLONG_MAX-x<y) {
        return ULLONG_MAX;
    } else {
        return x+y;
    }
}

unsigned long long bis(unsigned long long r, unsigned long long t)
{
    unsigned long long left=0, right=ULLONG_MAX;
    while(left<right-1) {
        unsigned long long mid=(left+right)/2;
        if(add(times(2,times(mid,mid)), times(2*r-1, mid))<=t) {
            left=mid;
        } else {
            right=mid;
        }
    }
    return left;
}

int main()
{
    int T, Tcnt=0;
    for(scanf("%d", &T); T; T--) {
        unsigned long long r, t;
        scanf("%llu%llu", &r, &t);
        printf("Case #%d: %llu\n", ++Tcnt, bis(r,t));
    }
    return 0;
}
