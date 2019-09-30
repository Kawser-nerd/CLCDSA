#include <iostream>
#include <vector>
#define INC(i, a, b) for(int i = a; i < b; ++i)
#define DEC(i, a, b) for(int i = a; i > b; --i)
#define REP(i, n)    for(uint i = 0; i < n; ++i)

typedef unsigned int uint;
typedef unsigned long ul;
typedef long long  ll;
typedef unsigned long long ull;

using namespace std;

vector<int> d;
vector<int> h;

int myabs(int x){
    return x > 0? x: -x;
}

int min(int a, int b){
    return a < b? a : b;
}

int dp(int index, int N){
    if(d[index] != -1){
        return d[index];
    }
    
    if(index == N - 1){
        return d[index] = 0;
    }else if(index == N - 2){
        return d[index] = myabs(h[index] - h[index + 1]);
    }else{
        return d[index] = min(
            dp(index + 1, N) + myabs(h[index] - h[index + 1]),
            dp(index + 2, N) + myabs(h[index] - h[index + 2])
        );
    }
}

int main(){
    uint N; cin >> N;
    int temp;
    REP(i, N){
        cin >> temp;
        h.push_back(temp);
    }

    REP(i, N){
       d.push_back(-1);
    }

    cout << dp(0, N) << endl;
    return 0;
}

/*
????dp
dp[index]
? index???????????????????
??????dp????!!
*/