#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <random>
#include <fstream>
#include <string>
#include <tuple>
#include <deque>

#define REP(i, N) for(int i = 0; i< N; i++)
using namespace std;
#define ll long long
const int INF = 1 << 29;

const int MOD = 1000000007;

vector<int> ab[100010];
int konokazu[100100] = {0};
ll dpf[100100] = {0};
ll dpg[100100] = {0};
bool tootta[100010] = {false};
int N;

int kyori(int genzaichi){
    
    bool hasi = true;
    tootta[genzaichi] = true;
    while(!ab[genzaichi].empty()){
        int tuginogenzaichi = ab[genzaichi][0];
        ab[genzaichi].erase(ab[genzaichi].begin());
        if(!tootta[tuginogenzaichi]){
            kyori(tuginogenzaichi);
            dpf[genzaichi] = (dpg[tuginogenzaichi] * dpf[genzaichi]) % MOD;
            dpg[genzaichi] = (dpf[tuginogenzaichi] * dpg[genzaichi]) % MOD;
        }
    }
    dpf[genzaichi] += dpg[genzaichi];
    dpf[genzaichi] %= MOD;
    dpg[genzaichi] %= MOD;
    return 0;
}
int nurie(){
    //treeDP
    cin >> N;
    REP(i, N - 1){
        int a,b;
        cin >> a >> b;
        ab[a].push_back(b);
        ab[b].push_back(a);
    }
    REP(i, N + 1){
        dpf[i] = 1;
        dpg[i] = 1;
    }
    
    tootta[1] = true;
    kyori(1);
    
    return dpf[1];
}

int main(){
    printf("%d\n",nurie());
}