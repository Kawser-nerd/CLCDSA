#include <stdio.h>
#include <iostream>

using namespace std;
#define NUM 300010
#define INF 1000000000

int A[NUM];
int B[NUM];
char V[NUM];

int main(void){
    int N;
    scanf("%d", &N);

    scanf("%s", V);

    for(int i = 0; i < N; i++){
        if(i == 0){
            A[i] = 0;
            continue;
        }
        if(V[i - 1] == 'W'){
            A[i] = A[i - 1] + 1;
        }else{
            A[i] = A[i - 1];
        }
    }

    for(int i = 0; i < N; i++){
        if(i == 0){
            B[N - 1 - i] = 0;
            continue;
        }
        if(V[N - i] == 'E'){
            B[N - i - 1] = B[N - i] + 1;
        }else{
            B[N - i - 1] = B[N - i];
        }
    }

    int min_ = INF;
    for(int i = 0 ; i < N; i++){
        min_ = min(min_, A[i] + B[i]);
    }

    /*
    for(int i = 0; i < N; i++){
        printf("%d, %c  %d %d\n",i, V[i],  A[i], B[i]);
    }
    */

    printf("%d\n", min_);

}