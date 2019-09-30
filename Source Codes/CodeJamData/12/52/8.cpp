#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 108;

bool mark[MAXN][MAXN];
char board[MAXN][MAXN];
int tag[MAXN][MAXN];

int bin(int i) {
    return 1 << i;
}

const char *output[8] = {
    "none",
    "bridge",
    "fork",
    "bridge-fork",
    "ring",
    "bridge-ring",
    "fork-ring",
    "bridge-fork-ring"
};

const int dx[6] = {-1, -1, 0, 0, 1, 1};
const int dy[6] = {-1, 0, -1, 1, 0, 1};

void floodfill(int x, int y, char z) {
    if (!mark[x][y] && board[x][y] == z) {
        mark[x][y] = true;
        for (int i = 0; i < 6; ++i) {
            floodfill(x + dx[i], y + dy[i], z);
        }
    }
}

int main() {
    int re, n, m, nn, x, y, ans;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &m);
        nn = n + n;
        fill(board[0], board[MAXN], '#');
        fill(tag[0], tag[nn], 0);
        for (int i = 1; i < nn; ++i) {
            int l = max(1, i - (n - 1));
            int r = min(nn - 1, n + (i - 1));
            for (int j = l; j <= r; ++j) {
                board[i][j] = '.';
                if (i == 1) {
                    tag[i][j] |= bin(0);
                }
                if (i == nn - 1) {
                    tag[i][j] |= bin(1);
                }
                if (j == l) {
                    if (i <= n) {
                        tag[i][j] |= bin(2);
                    }
                    if (i >= n) {
                        tag[i][j] |= bin(3);
                    }
                }
                if (j == r) {
                    if (i <= n) {
                        tag[i][j] |= bin(4);
                    }
                    if (i >= n) {
                        tag[i][j] |= bin(5);
                    }
                }
            }
        }
        for (int i = 1; i < nn; ++i) {
            for (int j = 1; j < nn; ++j) {
                if (__builtin_popcount(tag[i][j]) > 1) {
                    // printf("[%d][%d] = %o\n", i, j, tag[i][j]);
                    tag[i][j] = -1;
                }
            }
        }

        printf("Case #%d: ", ri);
        ans = 0;
        for (int k = 0; k < m; ++k) {
            scanf("%d%d", &x, &y);
            if (ans > 0) {
                continue;
            }
            fill(mark[0], mark[nn], false);
            board[x][y] = 'x';
            floodfill(x, y, 'x');
            int edge = 0, corner = 0;
            for (int i = 1; i < nn; ++i) {
                for (int j = 1; j < nn; ++j) {
                    if (mark[i][j]) {
                        if (tag[i][j] == -1) {
                            // printf("-> %d %d\n", i, j);
                            ++corner;
                        } else if (tag[i][j] > 0) {
                            edge |= tag[i][j];
                        }
                    }
                }
            }
            // printf("edge = %d\n", edge);
            if (corner >= 2) {
                ans |= bin(0);
            }
            if (__builtin_popcount(edge) >= 3) {
                ans |= bin(1);
            }
            for (int i = 1; i < nn; ++i) {
                for (int j = 1; j < nn; ++j) {
                    if (tag[i][j] != 0) {
                        floodfill(i, j, '.');
                    }
                }
            }
            for (int i = 1; i < nn; ++i) {
                for (int j = 1; j < nn; ++j) {
                    if (board[i][j] == '.' && !mark[i][j]) {
                        ans |= bin(2);
                        break;
                    }
                }
            }
            if (ans > 0) {
                printf("%s in move %d\n", output[ans], k + 1);
            }
        }
        if (ans == 0) {
            puts(output[ans]);
        }
    }

    return 0;
}

