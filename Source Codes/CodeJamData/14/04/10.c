#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort

int compare(double *t, double *s) {
    double f = *t - *s;
    return f > 0 ? 1 : (f < 0 ? -1 : 0);
}

double Ken[1000];
double Naomi[1000];

int main(void) {
    int num, try_num;
    int N;
    int i, j, k;


    scanf("%d", &num);
    for(try_num = 1; try_num <= num; ++try_num) {
        scanf("%d", &N);
        for(i = 0; i < N; ++i) {
            scanf("%lf", Naomi+i);
        }
        for(i = 0; i < N; ++i) {
            scanf("%lf", Ken+i);
        }
        qsort(Ken, N, sizeof(double), (int (*)(const void *, const void *))compare); // ¸‡
        qsort(Naomi, N, sizeof(double), (int (*)(const void *, const void *))compare);
        printf("Case #%d:", try_num);

        // ‰R‚Â‚«
        for(i = 0, j = 0, k = 0; j < N; ++j) {
            if(Ken[i] < Naomi[j]) { // Å¬‚ÌŽè‚Å‘ŠŽè‚ÉŸ‚Â
                ++i; ++k;
            }
            // Å¬‚ÌŽè‚Í‘ŠŽè‚ÌÅ‘åŽè‚ð‚Â‚Ô‚·‚Ì‚ÉŽg‚¤
        }
        printf(" %d", k);

        // ³’¼
        for(i = N-1, j = N-1, k = 0; i >= 0; --i, --j) {
            while(Ken[i] < Naomi[j] && j >= 0) {
                --j; ++k;
            }
        }
        printf(" %d\n", k);
    }

    return 0;
}
