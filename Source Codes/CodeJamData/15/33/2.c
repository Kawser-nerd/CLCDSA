#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

int C, D, V;
long long din[101];
long long target;


int solve(void) {
    int c = 0;
    int i = 0;
    target = 1;
    din[D] = V+1;

    while(target <= V) {
        if(din[i] <= target) {
            target += din[i] * C;
            ++i;
        }
        else {
            target += target * C; // add "target" coin
            ++c;
        }
    }

    return c;
}

int main(void) {
    int dataset_num, case_num;
    int i, j, k;


    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        scanf("%d %d %d", &C, &D, &V);
        for(i = 0; i < D; ++i) {
            scanf("%lld", din+i);
        }


        printf("Case #%d: %d\n", case_num, solve());
    }

    return 0;
}
