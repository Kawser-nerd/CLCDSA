#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define N_MAX 300

char S[N_MAX][N_MAX + 1];

char f(int i, int j, int N){
    if(N <= i){
        i = i - N;
    }
    if(N <= j){
        j = j - N;
    }

    return S[i][j];
}

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%s", S[i]);
    }

    int sum = 0;
    for(int k = 0; k < N; k++){
        bool is_good = true;
        for(int i = 0; i < N; i++){
            if(!is_good){
                continue;
            }
            for(int j = i + 1; j < N; j++){
                if(f(i + k, j, N) != f(j + k, i, N)){
                    is_good = false;
                    break;
                }
            }
        }
        if(is_good){
            sum += 1;
        }
    }

    printf("%d\n", sum * N);
}