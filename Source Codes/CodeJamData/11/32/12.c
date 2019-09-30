// http://code.google.com/codejam
// Task: 

#include <stdio.h>
#include <stdlib.h>

int N;
int d[1000];
int tt;

int f(int n1, int n2) {
    int t = 0.0;
    for (int n=0; n<N; ++n) {
        if (n1 == n || n2 == n) {
            int left = tt - t;
            if (left <= 0) {
                t += d[n];
            } else if (left > 2*d[n]) {
                t += 2*d[n];
            } else {
                t += left;
                t += d[n]-left/2;
            }
        } else {
            t += 2*d[n];
        }
    }
    return t;
}


int main ()
{
    int T; // Number of tests
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        int L, C;
        scanf("%d %d %d %d", &L, &tt, &N, &C);
        int a[C];
        for(int c = 0; c < C; ++c) {
            scanf("%d", &a[c]);
        }
        for (int n=0; n<N; ++n) {
            d[n] = a[n%C];
        }

        //printf("!!! N=%d:", N);
        //for (int n=0; n<N; ++n) { printf(" %d", d[n]); }
        //printf("\n");

        int sMin = f(-1, -1);
        if (L == 1) {
            for (int n=0; n<N; ++n) {
                int s = f(n, -1);
                if (s < sMin) sMin = s;
            }
        }

        if (L == 2) {
            for (int n1=0; n1<N; ++n1) {
                for (int n2=n1+1; n2<N; ++n2) {
                    int s = f(n1, n2);
                    if (s < sMin) sMin = s;
                }
            }
        }

        printf("Case #%d: %d\n", t, sMin);
    }
    return 0;
}
