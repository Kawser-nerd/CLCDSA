#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOR(i, a, b) for(i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define comp(a, b) comp(const void *a, const void *b)
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

int main(){
    uint N, M;
    scanf("%u %u", &N, &M);
    uint a, b;
    char mat[N][2];
    uint i, j;
    REP(i, N){
        REP(j, 2){
            mat[i][j] = 0;
        }
    }
    REP(i, M){
        scanf("%u %u", &a, &b);
        if(a == 1){
            mat[b - 1][0] = 1;
        }else if(a == N){
            mat[b - 1][1] = 1;
        }else if(b == 1){
            mat[a - 1][0] = 1;
        }else if(b == N){
            mat[a - 1][1] = 1;
        }
    }
    char flag = 0;
    REP(i, N){
        if(i!=0 && i!= N - 1){
        flag |= mat[i][0] && mat[i][1];
        if(flag){
            break;
        }
        }
    }
    TF_print(flag, "POSSIBLE", "IMPOSSIBLE");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%u %u", &N, &M);
     ^
./Main.c:33:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%u %u", &a, &b);
         ^