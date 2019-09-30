#include <stdio.h>

long long gcd(long long p, long long q)
{
    if(q==0) return p;
    return gcd(q, p%q);
}

int main()
{
    int T, Tcnt=0;
    for(scanf("%d", &T); T; T--) {
        long long p, q;
        long long comm;
        int cnt;
        scanf("%lld/%lld", &p, &q);
        comm = gcd(p, q);
        p/=comm;
        q/=comm;
        cnt=0;
        while(q%2==0) {
            if(q>p) cnt++;
            q/=2;
        }
        printf("Case #%d: ", ++Tcnt);
        if(q!=1) {
            puts("impossible");
        } else {
            printf("%d\n", cnt);
        }
    }
    return 0;
}

