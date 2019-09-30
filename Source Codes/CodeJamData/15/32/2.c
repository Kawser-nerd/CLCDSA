#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

int K, L, S;

char keys[101];
char target[101];

double key_ratio[26];
int key_num[26];

int calc_bananas(void) {
    int i, j;
    int c;
    for(i = 1; i < L; ++i) {
        for(j = 0; target[i+j] != '\0'; ++j) {
            if(target[j] != target[i+j]) break;
        }
        if(target[i+j] == '\0') break;
    }
    for(c = 0; i * c + L <= S; ++c) ;
    return c;
}

double once_typable(void) {
    int i;
    double t = K;
    double ratio = 1.0;
    for(i = 0; i < K; ++i) {
        ++(key_num[keys[i]-'A']);
    }
    for(i = 0; i < 26; ++i) {
        key_ratio[i] = (double)(key_num[i])/t;
    }
    for(i = 0; i < L; ++i) {
        ratio *= key_ratio[target[i]-'A'];
    }
    return ratio;
}



double solve(void) {
    double bananas = (double)calc_bananas();
    double ratio = once_typable();

    //printf("%lf %lf\n", bananas, ratio);
    if(ratio == 0.0) return 0.0; // cannot make sentence

    return bananas-ratio*(S-L+1);
}

int main(void) {
    int dataset_num, case_num;
    int i;


    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        scanf("%d %d %d", &K, &L, &S);
        for(i = 0; i < 26; ++i) {
            key_ratio[i] = 0.0;
            key_num[i] = 0;
        }
        gets(keys); // to skip the newline
        gets(keys);
        gets(target);
        keys[K] = '\0';
        target[L] = '\0';

        printf("Case #%d: %.7lf\n", case_num, solve());
    }

    return 0;
}
