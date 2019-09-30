#include <cstdio>

constexpr int MAX_N = 100100;

using namespace std;

int n;
char arr[MAX_N];

char opt[4][MAX_N];

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]);
    }

    opt[0][0] = 'S';
    opt[0][1] = 'S';
    opt[1][0] = 'S';
    opt[1][1] = 'W';
    opt[2][0] = 'W';
    opt[2][1] = 'S';
    opt[3][0] = 'W';
    opt[3][1] = 'W';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (opt[j][i] == 'S' && opt[j][i + 1] == 'S') {
                if (arr[i] == 'o') {
                    opt[j][i + 2] = 'S';
                } else {
                    opt[j][i + 2] = 'W';
                }
            } else if (opt[j][i] == 'S' && opt[j][i + 1] == 'W') {
                if (arr[i] == 'o') {
                    opt[j][i + 2] = 'W';
                } else {
                    opt[j][i + 2] = 'S';
                }
            } else if (opt[j][i] == 'W' && opt[j][i + 1] == 'S') {
                if (arr[i] == 'o') {
                    opt[j][i + 2] = 'W';
                } else {
                    opt[j][i + 2] = 'S';
                }
            } else {
                if (arr[i] == 'o') {
                    opt[j][i + 2] = 'S';
                } else {
                    opt[j][i + 2] = 'W';
                }
            }
        }
    }

    int which = -1;

    for (int i = 0; i < 4; i++) {
        if (opt[i][0] == opt[i][n] && opt[i][1] == opt[i][n + 1]) {
            which = i;
            break;
        }
    }

    if (which == -1) {
        printf("-1\n");
    } else {
        for (int i = 1; i <= n; i++) {
            printf("%c", opt[which][i]);
        }
        printf("\n");
    }

    return 0;
}