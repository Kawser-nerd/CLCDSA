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
int R, C;
int room[100000];

long long search(int n, long long unhap, int i, int j) {
    long long min = 9999999999999LL;
    if(n == N) {
        //printf("\t%lld\n", unhap);
        return unhap;
    }
    while(i <= R) {
        while(j <= C) {
            if(!room[i*(C+2)+j]) {
                int t = 0;
                long long x;
                room[i*(C+2)+j] = 1;
                if(room[i*(C+2)+j-1]) ++t;
                if(room[i*(C+2)+j+1]) ++t;
                if(room[(i-1)*(C+2)+j]) ++t;
                if(room[(i+1)*(C+2)+j]) ++t;
                x = search(n+1, unhap+t, i, j+1);
                room[i*(C+2)+j] = 0;
                if(x < min) min = x;
            }
            ++j;
        }
        ++i; j = 1;
    }
    return min;
}


int main(void) {
    int dataset_num, case_num;
    int i, j, k;
    int mul;

    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        scanf("%d %d %d", &R, &C, &N);
        mul = (R+2) * (C+2);
        for(i = 0; i < mul; ++i) {
            room[i] = 0;
        }

        printf("Case #%d: %lld\n", case_num, search(0,0LL, 1, 1));
    }

    return 0;
}
