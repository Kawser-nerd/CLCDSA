#include <cstdio>
using namespace std;

char t[4][4];

bool check(char c) {
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            if (t[i][j] == 'T') {
                t[i][j] = c;
            }
        }
    }

    for (int i=0; i<4; ++i) {
        bool ok = true;
        for (int j=0; j<4; ++j) {
            if (t[i][j] != c) {
                ok = false;
            }
        }
        if (ok) {
            printf("%c won\n", c);
            return true;
        }
    }

    for (int i=0; i<4; ++i) {
        bool ok = true;
        for (int j=0; j<4; ++j) {
            if (t[j][i] != c) {
                ok = false;
            }
        }
        if (ok) {
            printf("%c won\n", c);
            return true;
        }
    }

    bool ok = true;
    for (int i=0; i<4; ++i) {
        if (t[i][i] != c) {
            ok = false;
        }
    }
    if (ok) {
        printf("%c won\n", c);
        return true;
    }

    ok = true;
    for (int i=0; i<4; ++i) {
        if (t[i][3-i] != c) {
            ok = false;
        }
    }
    if (ok) {
        printf("%c won\n", c);
        return true;
    }
    return false;
}

int counter = 0;
void make() {
    printf("Case #%d: ", ++counter);

    bool full = true;
    int c1 = 0, c2 = 0;
    for(int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            scanf(" %c", &t[i][j]);
            if (t[i][j] == 'X') ++c1;
            if (t[i][j] == 'O') ++c2;
            if (t[i][j] == '.') full = false;
        }
    }

    if (c1 == c2) {
        if (check('O')) {
            return;
        }
    } else {
        if (check('X')) {
            return;
        }
    }

    if (full) {
        printf("Draw\n");
    } else {
        printf("Game has not completed\n");
    }
    return;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        make();
    }
    return 0;
}
