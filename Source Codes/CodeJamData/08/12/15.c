#include <stdio.h>

int main(char ** argv, int argc)
{
    int C;
    int N, M;
    int data[110][11];
    int c[110];
    int a, b;
    int i, j,k, cc;
    int ans,sol;
    int count = 0;

    scanf("%d", &C);
    cc = 0;
    while (C --)
    {
        ans = -1;
        sol = 0;
        cc ++;
        scanf("%d", &N);
        scanf("%d", &M);

        for (i = 0; i < M; i++)
        {
            scanf("%d", &count);
            c[i] = count;
            for (j = 0; j < count; j ++) {
                scanf("%d %d", &a, &b);
                if (b == 1) {
                    a = -a;
                }
                data[i][j] = a;
            }
        }

        for (i = 0; i < (1 << N); i ++)
        {
            int lans = __builtin_popcount(i);
            int match = 1;
            for (j = 0; j < M; j ++)
            {
                int got = 0;
                for (k = 0; k < c[j]; k ++)
                {
                    int x = data[j][k];
                    int y = 0;
                    if (x < 0) { x = -x; y = 1; }
                    x --;
                    if ((i & 1 << x) == (y << x)) {
                        got = 1;
                        break;
                    }
                }

                if (got == 0) {
                    match = 0;
                    break;
                }
            }
            if (match == 1) {
                if (ans == -1 || (lans < ans)) {
                    ans = lans;
                    sol = i;
                }
            }
        }

        printf("Case #%d: ", cc);
        if (ans != -1) {
            for (i = 0; i < N; i ++)
            {
                if (sol & (1 << i)) {
                    printf("1");
                }
                else {
                    printf("0");
                }

                if (i != N -1)
                {
                    printf(" ");
                }
            }
        }
        else {
            printf("IMPOSSIBLE");
        }
            printf("\n");
    }
    return 0;
}
