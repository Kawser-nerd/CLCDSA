#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOR(i, a, b) for(i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define comp(a, b) int comp(const void *a, const void *b)
#define MOD  1000000007

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ull;

void TF_print(char boolean, char T[], char F[]){
    if(boolean){
        printf("%s\n", T);
    }else{
        printf("%s\n", F);
    }
}

comp(a, b){
    return *(uint*)a -*(uint*)b;
}

int main(){
    uint N;
    scanf("%u", &N);
    uint S[N], i, full = 0;
    REP(i, N){
        scanf("%u", &S[i]);
        full += S[i];
    }
    qsort(S, N, sizeof(uint), comp);
    if(full % 10 == 0){
        REP(i, N){
            if(S[i] % 10 != 0){
                full -= S[i];
                break;
            }
        }
    }
    if(full % 10 == 0){
        printf("0\n");
    }else{
        printf("%u\n", full);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%u", &N);
     ^
./Main.c:31:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%u", &S[i]);
         ^