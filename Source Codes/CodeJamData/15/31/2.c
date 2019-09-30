#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

int R, C, W;

int solve(void) {
    int t = 0;
    int y = C;
    int i;
    for(i = 1; y > 2*W-1; ++i) {
        y -= W;
    }
    t = i*R + W;
    if(W == y) --t;
    return t;
}



int main(void) {
    int dataset_num, case_num;
    int i, j, k;


    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        scanf("%d %d %d", &R, &C, &W);

        printf("Case #%d: %d\n", case_num, solve());
    }

    return 0;
}
