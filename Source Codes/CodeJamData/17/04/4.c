#include <stdio.h>

int A[100][100];
int B[100][100];

int main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);

    int t, ti;
    scanf("%i", &t);
    for (ti = 1; ti <= t; ++ti) {
        int n, m;
        int i, j;
        scanf("%i%i\n", &n, &m);

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                A[i][j] = 0;
            }
        }

        for (i = 0; i < m; ++i) {
            char c;
            int x, y;
            scanf("%c%i%i\n", &c, &x, &y);
            --x;
            --y;

            if (c == '.') A[x][y] = 0;
            if (c == '+') A[x][y] = 1;
            if (c == 'x') A[x][y] = 2;
            if (c == 'o') A[x][y] = 3;
        }


        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                B[i][j] = A[i][j];
            }
        }

        int p = 0;
        for (j = 0; j < n; ++j) {
            if (A[0][j] == 2 || A[0][j] == 3) {
                p = j;
                break;
            }
        }

        A[0][p] = 3;

        for (j = 0; j < n; ++j) {
            if (j != p) A[0][j] = 1;
        }

        for (i = 1; i < n; ++i) {
            if (i == p) A[i][0] = 2;
            else A[i][i] = 2;
        }

        for (j = 1; j < n - 1; ++j) {
            A[n - 1][j] = 1;
        }

        int val = 0;
        int count = 0;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (A[i][j] == 1 || A[i][j] == 2) val += 1;
                if (A[i][j] == 3) val += 2;

                if (A[i][j] != B[i][j]) ++count;
            }
        }

        printf("Case #%i: %i %i\n", ti, val, count);

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (A[i][j] != B[i][j]) {
                    if (A[i][j] == 1) printf("+");
                    if (A[i][j] == 2) printf("x");
                    if (A[i][j] == 3) printf("o");

                    printf(" %i %i\n", i + 1, j + 1);
                }
            }
        }
    }

    return 0;
}
