#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

LL MOD = 1000000007LL;

LL inv(LL a, LL p){
    LL res = 1;
    while(p>0){
        if(p&1)res = (res*a)%MOD;
        a = (a*a)%MOD;
        p >>= 1;
    }
    return res;
}

int main(){
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    H--;
    W--;
    int C = H-A;
    int D = W-B;
    int M = min(C, D);
    LL res = 0LL;
    //cout << C << "," << D << endl;
    int Z = max(B+C, A+D) + 1;
    vector<LL> X(B+C+1, 1);
    vector<LL> Y(A+D+1, 1);
    REP(i, B+C){
        X[i+1] = X[i] * (B+C-i);
        X[i+1] %= MOD;
        X[i+1] *= inv(i+1, MOD-2);
        X[i+1] %= MOD;
    }
    REP(i, A+D){
        Y[i+1] = Y[i] * (A+D-i);
        Y[i+1] %= MOD;
        Y[i+1] *= inv(i+1, MOD-2);
        Y[i+1] %= MOD;
    }

    REP(i, M+1){
        //cout << X[B+i] << "," << Y[A+i] << endl;
        res += (X[B+i] * Y[A+i]);
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}