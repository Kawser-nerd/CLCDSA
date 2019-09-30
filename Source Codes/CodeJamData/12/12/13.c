#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int A[1000];
int B[1000];



int main(void) {
    int num;
    int i;
    int j;
    int l;
    int m;
    int t;
    int level;
    int best_num;
    int best;
    scanf("%d", &num);
    for(i = 1; i <= num; ++i) {
        scanf("%d", &level);
        for(j = 0; j < level; ++j) {
            scanf("%d %d", A+j, B+j);
        }
        best = best_num = 0;
        while(1) {
            t = -1;
            for(j = 0; j < level; ++j) {
                if(best >= B[j]) {
                    t = j;
                    break;
                }
            }
            if(t >= 0) {
                if(A[t] != 1000000) {
                    B[t] = A[t] = 1000000;
                    best += 2;
                }
                else {
                    B[t] = 1000000;
                    ++best;
                }
                ++best_num;
            }
            else {
                l = -1;
                for(j = 0; j < level; ++j) {
                    if(best >= A[j]) {
                        if(l <= B[j]) {
                            t = j;
                            l = B[j];
                        }
                    }
                }
                if(t >= 0) {
                    ++best;
                    ++best_num;
                    A[t] = 1000000;
                }
                else {
                    break;
                }
            }
        }

        if(best != 2 * level) {
            printf("Case #%d: Too Bad\n", i);
        }
        else {
            printf("Case #%d: %d\n", i, best_num);
        }
    }

    return 0;
}

