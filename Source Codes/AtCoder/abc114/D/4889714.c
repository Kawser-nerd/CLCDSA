#include <stdio.h>

const int M = 25;
const int prime[25] = {  2,  3,  5,  7, 11, 13, 17, 19, 23, 
                        29, 31, 37, 41, 43, 47, 53, 59, 61,
                        67, 71, 73, 79, 83, 89, 93
                      }; 
int fact[25];

int comb(int a) {
    return a*(a-1)/2;
}

int main(void) {
    int i, N, d, res, two, four, fourteen, twentyfour, seventyfour, X;
    scanf("%d", &N);

    for (i=0;i<M;i++) {
        d = prime[i];
        do {
            res = N/d;
            fact[i] += res;
            d *= prime[i];
        } while (res > 0);
    }

    // i^74, i^24 j^2, i^14 j^4, i^4 j^4 k^2
    two = 0;
    four = 0;
    fourteen = 0;
    twentyfour = 0;
    seventyfour = 0;
    X = 0;
    for (i=0;i<M;i++) {
        if (fact[i] >= 74) seventyfour++;
        if (fact[i] >= 24) twentyfour++;
        if (fact[i] >= 14) fourteen++;
        if (fact[i] >= 4) four++;
        if (fact[i] >= 2) two++;
    }

    X += seventyfour;
    if (two >= 2) X += twentyfour*(two-1);
    if (four >= 2) X += fourteen*(four-1);
    if (two >= 3) X += four*(four-1)*(two-2)/2;

    // for (i=0;i<M;i++) printf("%2d,", fact[i]);
    // printf("\t");
    printf("%3d\n", X);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^