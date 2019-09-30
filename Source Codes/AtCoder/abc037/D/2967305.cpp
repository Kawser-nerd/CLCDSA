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

int a[1010][1010];
int H, W;
bool hajimeta[1010][1010] = {false};
ll keironokazu[1010][1010];

int dp(int genzaichih,int genzaichiw){
    
    if(!hajimeta[genzaichih][genzaichiw]){
        if(genzaichih != 0 && a[genzaichih][genzaichiw] < a[genzaichih - 1][genzaichiw]){
            keironokazu[genzaichih][genzaichiw] += dp(genzaichih - 1, genzaichiw);
        }if(genzaichiw != 0 && a[genzaichih][genzaichiw] < a[genzaichih][genzaichiw - 1]){
            keironokazu[genzaichih][genzaichiw] += dp(genzaichih, genzaichiw - 1);
        }if(genzaichih != H - 1 && a[genzaichih][genzaichiw] < a[genzaichih + 1][genzaichiw]){
            keironokazu[genzaichih][genzaichiw] += dp(genzaichih + 1, genzaichiw);
        }if(genzaichiw != W - 1 && a[genzaichih][genzaichiw] < a[genzaichih][genzaichiw + 1]){
            keironokazu[genzaichih][genzaichiw] += dp(genzaichih, genzaichiw + 1);
        }
    }
    hajimeta[genzaichih][genzaichiw] = true;
    keironokazu[genzaichih][genzaichiw] %= MOD;
    
    return keironokazu[genzaichih][genzaichiw];
}

int keiro(){
    int saidai = 0;
    cin >> H >> W;
    REP(i, H){
        REP(j,W){
            cin >> a[i][j];
            keironokazu[i][j] = 1;
        }
    }
    int saidaikeirosuu = 0;
    
    REP(i, H){
        REP(j, W){
            saidaikeirosuu += dp(i, j);
            saidaikeirosuu %= MOD;
        }
    }
    
    
    return saidaikeirosuu;
}

int main(){
    printf("%d\n", keiro());
} ./Main.cpp:15:20: warning: shift count >= width of type [-Wshift-count-overflow]
const ll llINF = 1 << 58;
                   ^  ~~
1 warning generated.