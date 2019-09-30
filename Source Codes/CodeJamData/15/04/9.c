#include <stdio.h>

/// @retval 0: can't fill (Richard)
/// @retval 1: can fill (Gabriel)
int solve(int X, int S, int B) {
    // always S <= B
    if (B < S) {
        int tmp = S;
        S = B;
        B = tmp;
    }

    if (X == 1) {
        return 1;
    }
    else if (X == 2) {
        if (B == 1) return 0;
        if ((B * S) % 2 == 0) return 1;
        return 0;
    }
    else if (X == 3) {
        if (B <= 2) return 0;
        if (S == 1) return 0;
        if ((B * S) % 3 == 0) return 1;
        else return 0;
    }
    else if (X == 4) {
        if (B <= 3) return 0;
        if (S <= 2) return 0;
        if ((B * S) % 4 == 0) return 1;
        else return 0;
    }
}

int main(void)
{
    /* int x, s, b; */
    /* for(x = 1; x <= 4; ++x) { */
    /*     for(s = 1; s <= 4; ++s) { */
    /*         for(b = s; b <= 4; ++b) { */
    /*             printf("x, s, b, result = %d, %d, %d, %d\n", x, s, b, solve(x, s, b)); */
    /*         } */
    /*     } */
    /* } */

    int T;
    scanf("%d", &T);
    int t = 0;
    for(t = 0; t < T; ++t) {
        int X, S, B;
        scanf("%d %d %d", &X, &S, &B);
        printf("Case #%d: %s\n", (t+1), (solve(X, S, B) ?  "GABRIEL" : "RICHARD"));
    }
    return 0;
}
