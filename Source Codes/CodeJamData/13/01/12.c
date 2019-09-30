#include <stdio.h>
int main() {
    char s[5];
    int T, wx[4], wo[4], kx[4], ko[4], empty, d1x, d2x, d1o, d2o, i, j, k, end;
    scanf("%d", &T);
    for (i=1; i<=T; i++) {
        for (j=0; j<4; j++)
            wx[j]=wo[j]=kx[j]=ko[j]=0;
        empty=d1x=d2x=d1o=d2o=0;
        for (j=0; j<4; j++) {
            scanf("%s", s);
            for (k=0; k<4; k++) {
                if (s[k]=='X' || s[k]=='T') {
                    wx[j]++;
                    kx[k]++;
                    if (k==j) d1x++;
                    if (3-k==j) d2x++;
                }
                if (s[k]=='O' || s[k]=='T') {
                    wo[j]++;
                    ko[k]++;
                    if (k==j) d1o++;
                    if (3-k==j) d2o++;
                }
                if (s[k]=='.') empty++;
            }
        }
        end=0;
        printf("Case #%d: ", i);
        for (j=0; j<4; j++) {
            if (wx[j]==4 || kx[j]==4 || d1x==4 || d2x==4)
                printf("X won\n"), end=1;
            else if (wo[j]==4 || ko[j]==4 || d1o==4 || d2o==4)
                printf("O won\n"), end=1;
            if (end==1) break;
        }
        if (end==0) { 
            if (empty==0)
                printf("Draw\n");
            else
                printf("Game has not completed\n");
        }
    }
}
