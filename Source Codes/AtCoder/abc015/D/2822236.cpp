#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <random>
#include <fstream>

#define REP(i, N) for(int i = 0; i< N; i++)
using namespace std;
#define ll long long

//long double kakuritu[102][222][222][222] = {0};
int juuyoudogoukei[51][10000][51] = {0};
int main(){
    int W, N, K;
    cin >> W;
    cin >> N >> K;
    int A[51];
    int B[51];
    REP(i, N){
        cin >> A[i] >> B[i];
    }
    REP(i, N){
        REP(j, W + 1){
            REP(k, K){
                if(j < A[i]){
                    juuyoudogoukei[i + 1][j][k + 1] = juuyoudogoukei[i][j][k + 1];
                }else{
                    juuyoudogoukei[i + 1][j][k + 1] = max(juuyoudogoukei[i][j][k + 1], juuyoudogoukei[i][j - A[i]][k] + B[i]);
                }
                //printf("%d\n",juuyoudogoukei[i + 1][j][k + 1]);
            }
        }
    }
    int saidaijuuyoudo = 0;
    REP(i, W + 1){
        REP(j, K ){
            saidaijuuyoudo = max(saidaijuuyoudo, juuyoudogoukei[N][i][j + 1]);
        }
    }
    printf("%d\n",saidaijuuyoudo);
}