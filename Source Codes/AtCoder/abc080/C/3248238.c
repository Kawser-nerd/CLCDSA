#include <stdio.h>
  
int  main() {
    int N;
    scanf("%d", &N);

    int F[100][14];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 10; j++)
            scanf("%d", &F[i][j]);

    int P[100][15];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 11; j++)
            scanf("%d", &P[i][j]);

    int res = -(1 << 30);
    for (int b = 1; b < (1 << 10); b++) {
        int cc = 0;
        for (int i = 0; i < N; i++) {
            int c = 0;
            for (int j = 0; j < 10; j++)
                if ((b >> j & 1) && F[i][j])
                    c++;

            cc += P[i][c];
        }
        if (res < cc)
            res = cc;
    }

    printf ("%d\n",res);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:10:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &F[i][j]);
             ^
./Main.c:15:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &P[i][j]);
             ^