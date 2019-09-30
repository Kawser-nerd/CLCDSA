#include<stdio.h>
#define MAX_LIMIT 1003

int A[MAX_LIMIT], N, P[MAX_LIMIT], maxCycle;

void check(int limit) {
    int i, okay = 1;
    for(i=0; i<limit; i++) {
        int c = P[i], l = (i==0)?P[limit-1]:P[i-1], r = (i==limit-1)?P[0]:P[i+1];
        if(A[c]!=l && A[c]!=r) {
            okay = 0;
            break;
        }
    }
    if(okay && limit>maxCycle) maxCycle = limit;
}

void perm(int index) {
    check(index);
    if(index==N) {
        return;
    }
    int i, j;
    for(j=0; j<N; j++) {
        int okay = 1;
        for(i=0; i<index; i++)
            if(P[i]==j) {
                okay = 0;
                break;
            }
        if(okay) {
            P[index] = j;
            perm(index+1);
        }
    }
}

int solve() {
    maxCycle = 0;
    perm(0);
    printf("%d\n", maxCycle);
}

int main() {
    int T, cas;
    scanf("%d", &T);
    for(cas=1; cas<=T; cas++) {
        scanf("%d", &N);
        int i;
        for(i=0; i<N; i++) {
            scanf("%d", &A[i]);
            A[i]--;
        }
        printf("Case #%d: ", cas);
        solve();
    }
    return 0;
}