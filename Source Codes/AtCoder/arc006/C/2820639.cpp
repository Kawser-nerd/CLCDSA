#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <random>
#include <fstream>

#define REP(i, N) for(int i = 0; i< N; i++)
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    int danball[50];
    REP(i, N){
        cin >> danball[i];
    }
    int yamanokazu = 1;
    int yama[50];
    yama[0] = danball[0];
    bool kasanerareta;
    REP(i, N){
        kasanerareta = false;
        REP(j, yamanokazu){
            if(danball[i] <= yama[j]){
                yama[j] = danball[i];
                kasanerareta = true;
                break;
            }
        }
        if(kasanerareta == false){
            yama[yamanokazu] = danball[i];
            yamanokazu++;
        }
    }
    cout << yamanokazu << endl;
}