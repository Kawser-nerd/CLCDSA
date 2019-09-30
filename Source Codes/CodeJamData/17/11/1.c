#include <stdio.h>

char A[26][26];

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int t, ti;
    scanf("%i", &t);
    for (ti = 1; ti <= t; ++ti) {
        printf("Case #%i:\n", ti);

        int r, c;
        scanf("%i%i", &r, &c);

        int i, j;
        for (i = 0; i < r; ++i) {
            scanf("%s", &A[i][0]);
        }

        for (i = 0; i < r; ++i) {
            for (j = 1; j < c; ++j) {
                if (A[i][j] == '?') A[i][j] = A[i][j - 1];
            }
            for (j = c - 2; j >= 0; --j) {
                if (A[i][j] == '?') A[i][j] = A[i][j + 1];
            }
        }

        for (i = 1; i < r; ++i) {
            for (j = 0; j < c; ++j) {
                if (A[i][j] == '?') A[i][j] = A[i - 1][j];
            }
        }

        for (i = r - 2; i >= 0; --i) {
            for (j = 0; j < c; ++j) {
                if (A[i][j] == '?') A[i][j] = A[i + 1][j];
            }
        }

        for (i = 0; i < r; ++i) {
            printf("%s\n", &A[i][0]);

        }
    }

    return 0;
}
