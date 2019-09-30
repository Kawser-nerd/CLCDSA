#include<stdio.h>
#include<stdlib.h>

int main(){
    int t, u, a, b, i, j;
    double p, tp[99999], stp, rtp, me, e;
    scanf("%d", &t);
    for (u = 1 ; u <= t ; ++u){
        scanf("%d%d", &a, &b);
        for (i = 0, stp = 1.0 ; i < a ; ++i){
            scanf("%lf", &p);
            tp[i] = stp * (1.0 - p);
            stp *= p;
        }
        tp[a] = stp;
        me = b + 2;
        for (i = 0, rtp = 1.0 ; i < a ; ++i){
            rtp -= tp[i];
            e = (a + b - i - i - 1) * rtp + (a + b + b - i - i) * (1 - rtp);
            if (e < me)me = e;
            //printf("%.3lf, %.3lf\n", rtp, e);
        }
        printf("Case #%d: %.6lf\n", u, me);
    }
    return 0;
}
