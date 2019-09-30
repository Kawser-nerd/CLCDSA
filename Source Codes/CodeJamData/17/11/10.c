#include <stdio.h>
#include <stdlib.h>

void printCake(int R, int C, char cake[][C]) {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            printf("%c", cake[r][c]);
        }
        printf("\n");
    }
}

int isEmpty(int R, int C, char cake[][C], int r1, int r2, int c1, int c2) {
    for (int r = r1; r <= r2; r++) {    
        for (int c = c1; c <= c2; c++) {
            if (cake[r][c] != '?') return 0;
        }
    }
    return 1;
}

void fill(int R, int C, char cake[][C], int r1, int r2, int c1, int c2, char x) {
    for (int r = r1; r <= r2; r++) {
        for (int c = c1; c <= c2; c++) {
            cake[r][c] = x;
        }
    }
}

void grow(int R, int C, char cake[][C], int r0, int c0) {
    char x = cake[r0][c0];
    // grow to the left.
    int c1 = c0 - 1, c2 = c0;
    while (c1 >= 0 && cake[r0][c1] == '?') cake[r0][c1--] = x;
    c1++;
    // grow up.
    int r1 = r0 - 1, r2 = r0;
    while (r1 >= 0 && isEmpty(R, C, cake, r1, r1, c1, c2)) {
        fill(R, C, cake, r1, r1, c1, c2, x);
        r1--;
    }
    r1++;
    // grow to the right.
    c2++;
    while (c2 < C && isEmpty(R, C, cake, r1, r2, c2, c2)) {
        fill(R, C, cake, r1, r2, c2, c2, x);
        c2++;
    }
    c2--;
    // grow down.
    r2++;
    while (r2 < R && isEmpty(R, C, cake, r2, r2, c1, c2)) {
        fill(R, C, cake, r2, r2, c1, c2, x);
        r2++;
    }    
}

void cakify(int R, int C, char cake[][C]) {
    int visited[26] = { 0 };
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (cake[r][c] != '?' && !visited[cake[r][c]-'A']) {
                grow(R, C, cake, r, c);
                visited[cake[r][c]-'A'] = 1;
            }
        }
    }
}

int main(void) {
    int T, R, C;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &R, &C);
        char cake[R][C];
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                scanf(" %c", &cake[r][c]);
            }
        }

        cakify(R, C, cake);
        
        printf("Case #%d:\n", t);
        printCake(R, C, cake);
    }
    return 0;
}
