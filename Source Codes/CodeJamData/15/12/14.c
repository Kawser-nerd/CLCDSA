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
int B;
int M[1000];

long long cutting_num(long long t) {
    long long acc = 0LL;
    int i;
    for(i = 0; i < B; ++i) {
        acc += t/(long long)(M[i]) + 1;
    }
    return acc;
}

int binsearch(long long left, long long right) {
    long long mid;
    long long cutm;
    int i;

    while(left + 1 < right) {
        mid = (right + left) / 2;
        if(cutting_num(mid) >= (long long)N) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    //printf("%lld %lld\n", left, right);
    N -= (int)cutting_num(left);
    for(i = 0; i < B; ++i) {
        if(right%(long long)(M[i]) == 0)
            if(--N == 0) return i+1;
    }
}



int main(void) {
    int dataset_num, case_num;
    int i, j, k;
    int t;
    int md;
    int acc;

    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        scanf("%d %d", &B, &N);
        for(i = 0; i < B; ++i) {
            scanf("%d", M+i);
        }

        printf("Case #%d: %d\n", case_num, binsearch(0, 100000LL*(long long)N));
    }

    return 0;
}
