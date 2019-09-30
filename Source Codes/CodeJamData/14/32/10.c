#include <stdio.h>
#include <string.h>
#define MOD 1000000007

char s[105][105];
int mark[105];
int let[26];
char con[1005];
int counter;
int n;
int len;

int check(void) {
    int i;
    char last;
    for (i = 0; i < 26; i++) {
        let[i] = 0;
    }

    last = '\0';
    for (i = 0; i < len; i++) {
        if (con[i] == last) {
            continue;
        } else {
            if (let[con[i] - 'a'] == 1) {
                return 0;
            } else {
                let[con[i] - 'a'] = 1;
                last = con[i];
            }
        }
    }
    return 1;
}

void backtrack(int used, int pos) {
    if (used == n) {
        con[pos] = '\0';
        if (check()) {
            counter++;
            counter %= MOD;
        }
        return;
    }

    int i, j;

    for (i = 0; i < n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            for (j = 0; s[i][j] != '\0'; j++) {
                con[pos + j] = s[i][j];
            }
            backtrack(used + 1, pos + j);
            mark[i] = 0;
        }
    }
    return;
}

int main(void) {
    int t;
    int i;
    int caso;

    scanf(" %d", &t);

    for (caso = 1; caso <= t; caso++) {
        scanf(" %d", &n);
        len = 0;
        for (i = 0; i < n; i++) {
            mark[i] = 0;
            scanf(" %s", s[i]);
            len += strlen(s[i]);
        }

        counter = 0;
        backtrack(0, 0);

        printf("Case #%d: %d\n", caso, counter);
    }
    return 0;
}


