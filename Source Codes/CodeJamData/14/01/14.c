#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/
int f[16];
int l[16];


int main(void) {
    int num;
    int N;
    int i, j, k;
    int p, n;
    int fc, lc;

    scanf("%d", &num);
    for(i = 1; i <= num; ++i) {
        p = -1; n = 0;
        scanf("%d", &fc);
        for(j = 0; j < 16; ++j) {
            scanf("%d", f+j);
        }
        scanf("%d", &lc);
        for(j = 0; j < 16; ++j) {
            scanf("%d", l+j);
        }
        for(j = 1; j <= 4; ++j) {
            for(k = 1; k <= 4; ++k) {
                if(f[fc*4-j] == l[lc*4-k]) {
                    p = f[fc*4-j]; ++n;
                }
            }
        }

        printf("Case #%d: ", i);
        switch(n) {
        case 1:
            printf("%d\n", p);
            break;
        case 0:
            printf("Volunteer cheated!\n");
            break;
        default:
            printf("Bad magician!\n");
            break;
        }
    }

    return 0;
}
