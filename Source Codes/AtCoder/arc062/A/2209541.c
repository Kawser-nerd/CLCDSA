#include <stdio.h>
#define FOR(i, a, b) for(i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)

typedef unsigned long long ull;

int main(){
    int T, A;
    int N;
    int i;
    ull inT, inA;
    scanf("%d", &N);

    REP(i, N){
        scanf("%d %d", &T, &A);
        if(i == 0){
            inT = T, inA = A;
        }else{
            ull tempA, tempT;
            int f;
            f = inA % A == 0? 0 : 1;
            tempA = (inA/A + f) * A;
            f = inT % T == 0? 0 : 1;
            tempT = (inT/T + f) * T;
            if(tempA/A < tempT/T){
                inT = tempT;
                inA = A * (tempT/T);
            }else{
                inA = tempA;
                inT = T * (tempA/A);
            }
        }
    }
    printf("%llu\n", inA + inT);
    return 0;
}

/*
????????X, Y??p:q??????.
X???p???????????X_p?, Y???q???????????Y_q????
X_p/p?Y_q/q???????????,
X = X_p, Y = q/p * X_p
????
X = p/q * Y_q, Y = Y_q
????????.
*/ ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &T, &A);
         ^