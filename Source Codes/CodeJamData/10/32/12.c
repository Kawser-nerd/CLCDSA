#include <stdio.h>
#include <math.h>

static int
solve(int L, int P, int C)
{
    double l = (double)L;
    double p = (double)P;
    double c = (double)C;
    int x = (int)((log(p/l)/log(c))-1.0e-9) + 1;
    int n = 0;
    while (x > (1<<n)) {
        n++;
    };
    return n;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int id = 1; id <= T; id++) {
        int L,P,C;
        scanf("%d%d%d",&L,&P,&C);
        printf("Case #%d: %d\n", id, solve(L,P,C));
    }
}
