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
const ll llINF = 1 << 58;

const int MOD = 1000000007;


int N, Q, K;
vector<int> ab[100010];
vector<int> c[100010];
long saitankyori[100010];
bool tootta[100010];

int kyori(int genzaichi, int maenogenzaichi){
    tootta[genzaichi] = true;
    while(!ab[genzaichi].empty()){
        int tuginogenzaichi = ab[genzaichi][0];
        long tuginogenzaichimadenokyori = c[genzaichi][0];
        ab[genzaichi].erase(ab[genzaichi].begin());
        c[genzaichi].erase(c[genzaichi].begin());
        if(tuginogenzaichi != maenogenzaichi){
            saitankyori[tuginogenzaichi] = saitankyori[genzaichi] + tuginogenzaichimadenokyori;
            kyori(tuginogenzaichi, genzaichi);
        }
    }
    return 0;
}
int transittreepath(){
    cin >> N;
    REP(i, N - 1){
        int a, b, c1;
        cin >> a >> b >> c1;
        ab[a].push_back(b);
        c[a].push_back(c1);
        ab[b].push_back(a);
        c[b].push_back(c1);
    }
    
    cin >> Q >> K;
    int x, y;
    long answers[100010];
    REP(i, N + 1){
        saitankyori[i] = INF;
        saitankyori[i] *= 256;
    }
    
    saitankyori[K] = 0;
    kyori(K, -1);
    
    REP(i, Q){
        cin >> x >> y;
        answers[i] = saitankyori[x] + saitankyori[y];
    }
    
    REP(i, Q){
        printf("%ld\n", answers[i]);
    }
    return 0;
}

/*
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
*/

int main(){
    transittreepath();
} ./Main.cpp:15:20: warning: shift count >= width of type [-Wshift-count-overflow]
const ll llINF = 1 << 58;
                   ^  ~~
1 warning generated.