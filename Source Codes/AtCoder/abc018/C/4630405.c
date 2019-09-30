#include <stdio.h>
#include <stdlib.h>
#define Rmax 500
#define sizeC 500
// ?????????
enum {
    black,
    white,
    green,
};
// ??
int R, C, K;
char **s;
int **board;
// ?????
void structBord (char **s, int **board) {
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            if (s[i][j] == 'o') {   // ????
                board[i][j] = white;
            } else if (s[i][j] == 'x') {    // ????
                board[i][j] = black;
            }
        }
    }
}
// ??????????
void  calcBoardSum (int **board) {
    for (size_t i = 1; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            if (board[i][j] != black) {
                board[i][j] += board[i-1][j];
            }
        }
    }
}
// ? i,j ??? K????????????
int check (int x, int y) {
    if (board[y][x] >= K) {
        for (int i = -K; i <= K; i++) {
            int dif = K - abs(i);   // ?????????
            int nx, ny;
            nx = x+i; ny = y+dif;
            if (nx<0 || nx>=C || ny<0 || ny>=R) {
                return 0;   // ???????
            }
            int boader = dif*2+1;
            if (board[ny][nx] < boader) {
                return 0;   // ???????
            }
        }
    } else {
        return 0;   // ???????
    }
    return 1;   // ??????
}
// ?????????
void countDiamonds (int R, int C, int K, int **board) {
    structBord(s, board);
    calcBoardSum(board);
    int cnt = 0;
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            cnt += check(j, i);
        }
    }
    printf("%d\n", cnt);
}

int main(int argc, char const *argv[]) {
    // ??
    scanf("%d %d %d", &R, &C, &K);
    K--;    // K???????
    // ?????????
    s = (char **)malloc(sizeof(char *)*R);
    board = (int **)malloc(sizeof(int *)*R);
    for (size_t i = 0; i < R; i++) {
        s[i] = (char *)malloc(sizeof(char)*(C+1));
        board[i] = (int *)malloc(sizeof(int)*C);
        scanf("%s", s[i]);  // ??????
    }
    // ??
    countDiamonds(R, C, K, board);
    // ?????
    for (size_t i = 0; i < R; i++) {
        free(s[i]);
        free(board[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:72:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &R, &C, &K);
     ^
./Main.c:80:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", s[i]);  // ??????
         ^