#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
int cs,an;
const int SIZE = 1010;
vector<int>e[SIZE];
int dp[SIZE];
void dfs(int x,int last){
    vector<int>d;
    dp[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        int sum=0;
        if(y==last)continue;
        dfs(y,x);
        d.PB(dp[y]);
    }
    if(SZ(d)>=2){
        sort(ALL(d));
        dp[x]+=d.back()+d[d.size()-2];
    }
}
int main(){
    int T,i,j,k,n;
    CASET{
        an=0;
        DRI(n);
        REPP(i,1,n+1)e[i].clear();
        REPP(i,1,n){
            DRII(x,y);
            e[x].PB(y);
            e[y].PB(x);
        }
        REPP(i,1,n+1){
            dfs(i,0);
            an=max(an,dp[i]);
        }
        printf("Case #%d: %d\n",case_n++,n-an);
    }
    return 0;
}

