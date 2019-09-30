#include <stdio.h>

int main() {
    int casN;
    char inp[5][5];
    scanf("%d", &casN);
    for (int casI = 0; casI < casN; casI++) {
        for (int i=0; i<4; i++) {
            scanf("%s", inp[i]);
        }
        bool xw = false, ow = false;
        for (int i=0; i<4; i++) {
            int xc = 0, oc = 0, tc = 0;
            for (int j=0; j<4; j++) {
                switch (inp[i][j]) {
                    case 'X':
                        xc++;
                        break;
                    case 'O':
                        oc++;
                        break;
                    case 'T':
                        tc++;
                        break;
                    default:
                        break;
                }
            }
            if (xc + tc >= 4) xw = true;
            if (oc + tc >= 4) ow = true;
        }
        for (int i=0; i<4; i++) {
            int xc = 0, oc = 0, tc = 0;
            for (int j=0; j<4; j++) {
                switch (inp[j][i]) {
                    case 'X':
                        xc++;
                        break;
                    case 'O':
                        oc++;
                        break;
                    case 'T':
                        tc++;
                        break;
                    default:
                        break;
                }
            }
            if (xc + tc >= 4) xw = true;
            if (oc + tc >= 4) ow = true;
        }
        for (int i=0; i<2; i++) {
            int xc = 0, oc = 0, tc = 0;
            for (int j=0; j<4; j++) {
                switch (inp[j][3*i - (2*i-1) * j]) {
                    case 'X':
                        xc++;
                        break;
                    case 'O':
                        oc++;
                        break;
                    case 'T':
                        tc++;
                        break;
                    default:
                        break;
                }
            }
            if (xc + tc >= 4) xw = true;
            if (oc + tc >= 4) ow = true;
        }
        if (xw) {
            printf("Case #%d: X won\n", casI+1);
            continue;
        }
        if (ow) {
            printf("Case #%d: O won\n", casI+1);
            continue;
        }
        int cell = 0;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                if (inp[i][j] != '.') cell ++;
            }
        }
        if (cell == 16) {
            printf("Case #%d: Draw\n", casI+1);
        } else {
            printf("Case #%d: Game has not completed\n", casI+1);
        }
    }
    return 0;
}
