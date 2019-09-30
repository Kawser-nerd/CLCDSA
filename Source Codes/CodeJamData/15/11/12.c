#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

int N;
int m[10000];

int main(void) {
    int dataset_num, case_num;
    int i, j, k;
    int acc;

    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        acc = 0;
        scanf("%d", &N);
        for(i = 0; i < N; ++i) {
            scanf("%d", m+i);
        }


        printf("Case #%d: ", case_num);
        for(i = 1; i < N; ++i) {
            if(m[i-1] > m[i]) acc += m[i-1]-m[i];
        }
        printf("%d ", acc);

        for(j = 0; j <= 10000; ++j) {
            int f = 1;
            for(i = 1; i < N; ++i) {
                if(m[i-1] - j > m[i]) { f = 0; break; }
            }
            if(f) break;
        }
        // j is Kaylin eating mash/10s
        acc = 0;
        for(i = 1; i < N; ++i) {
            if(m[i-1] - j < 0) acc += m[i-1];
            else acc += j;
        }
        printf("%d\n", acc);
    }

    return 0;
}
