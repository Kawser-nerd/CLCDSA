#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <random>
#include <fstream>
#include <string>

#define REP(i, N) for(int i = 0; i< N; i++)
using namespace std;
#define ll long long
const int INF = 1 << 29;

const int mod = 1000000007;

int nibutansaku(int array[], int n, int arraylength){
    int r = -1;
    int l = arraylength - 1;
    int m;
    while(l - r > 1){
        m = (l - r) / 2 + r;
        if(array[m] < n) r = m;
        else l = m;
        
    }
    
    return l;
}

int trumpinsert2(){
    int N;
    cin >> N;
    int c[30010];
    int trumpdp[30010];
    REP(i, N){
        cin >> c[i];
    }
    
    int dp[30010] = {0};
    dp[0] = c[0];
    int len = 1;
    REP(i, N - 1){
        if(c[i + 1] < dp[0]) dp[0] = c[i + 1];
        else if(c[i + 1] > dp[len - 1]){
            dp[len] = c[i + 1];
            len ++;
        }else{
            int idx = nibutansaku(dp, c[i + 1], len);
            dp[idx] = c[i + 1];
        }
    }
    
    return N - len;
}

int main(){
    printf("%d\n",trumpinsert2());
}