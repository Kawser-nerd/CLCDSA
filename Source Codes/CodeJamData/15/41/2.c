#include <stdio.h>
char s[108][108];

int r, c;

int hasArrow(int i, int j, int rd, int cd) {
    i += rd;
    j += cd;
    while (0 <= i && i < r && 0 <= j && j < c) {
        if (s[i][j] != '.'){ return 1; }
        i += rd;
        j += cd;
    }
    return 0;
}

int solve() {
    int g = 0;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            int rd, cd;
            switch (s[i][j]) {
                case '.': continue;
                case '<': rd = 0; cd = -1; break;
                case '>': rd = 0; cd =  1; break;
                case '^': rd = -1; cd = 0; break;
                case 'v': rd =  1; cd = 0; break;
            }
            if (hasArrow(i, j, rd, cd)){
                continue;
            }
            if (!hasArrow(i, j, -rd, -cd) &&
                !hasArrow(i, j, cd, -rd) &&
                !hasArrow(i, j, -cd, rd)) {
                return -1;
            }
            g++;
        }
    }
    return g;
}

void tc() {
    scanf("%d%d", &r, &c);
    scanf(" ");
    for (int i = 0; i < r; ++i){
        fgets(s[i], 108, stdin);
    }
    int so = solve();
    if (so == -1) printf("IMPOSSIBLE\n");
    else printf("%d\n", so);
}

int main() {
    int tcn; scanf("%d", &tcn);
    for (int tci = 1; tci <= tcn; ++tci) {
        printf("Case #%d: ", tci);
        tc();
    }
    return 0;
}

