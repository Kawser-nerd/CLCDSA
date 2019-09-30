#include <stdio.h>
#include <string.h>

static int
hex2i(char c) {
    if (c <= '9')
        return c - '0';
    return 10 + c - 'A';
}

static int
check(int i, int j, int M, int N, char board[M][N])
{
    int k = 2;
    char c = board[i][j];
    for (;i+k<=M&&j+k<=N;k++) { 
        for (int I = 0; I < k; I++) {
            char c2 = board[i+I][j+k-1];
            if (c2 == c || c2 ==2)
                goto finish;
            c = c2;
        }
        for (int J = k-1; J > 0; J--) {
            char c2 = board[i+k-1][j+J-1];
            if (c2 == c || c2 ==2)
                goto finish;
            c = c2;
        }
    }
finish:
    return k-1;
}

static int table[512];

static int
solve(int M, int N, char board[M][N])
{
    int maxi = 0, maxj = 0, max = 0;
    memset(table, 0, sizeof(table));

    for (;;) {
        maxi = 0; maxj = 0; max = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] != 2) {
                    int sz = check(i,j,M,N,board);
                    if (sz > max) {
                        maxi = i;
                        maxj = j;
                        max  = sz;
                    }
                }
            }
        }
        /* mark */
        for (int i = 0; i < max; i++) {
            for (int j = 0; j < max; j++) {
                board[i+maxi][j+maxj] = 2;
            }
        }
        if (max == 0)
            break;
        table[max-1]++;
    }

    int K =0;
    for (int i = 0; i < 512; i++) {
        if (table[i] != 0)
            K++;
    }
    return K;
}

int
main(void)
{
    int T;
    scanf("%d", &T);
    for (int id = 1; id <= T; id++) {
        int M,N;
        scanf("%d%d", &M, &N);
        char input[M][N/4+1];
        for (int i = 0; i < M; i++) {
            scanf("%s", input[i]);
        }
        char board[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N/4; j ++) {
                board[i][4*j]   = (hex2i(input[i][j]) & 8) != 0;
                board[i][4*j+1] = (hex2i(input[i][j]) & 4) != 0;
                board[i][4*j+2] = (hex2i(input[i][j]) & 2) != 0;
                board[i][4*j+3] = (hex2i(input[i][j]) & 1) != 0;
            }
        }
        printf("Case #%d: %d\n", id, solve(M,N,board));
        for (int i = 511; i >= 0; i--) {
            if (table[i] > 0)
                printf("%d %d\n", i+1, table[i]);
        }
    }
    return 0;
}
