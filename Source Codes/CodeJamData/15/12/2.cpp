#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
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
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
LL M[SIZE];
int main(){
    CASET{
        DRII(B,N);
        LL ll=0,rr=1e15;
        REP(i,B)cin>>M[i];
        while(ll<rr){
            LL mm=(ll+rr)>>1;
            LL sum=0;
            REP(i,B){
                sum+=mm/M[i]+1;
            }
            if(sum>=N)rr=mm;
            else ll=mm+1;
        }
        LL sum=0;
        vector<int>d;
        REP(i,B){
            sum+=ll/M[i]+1;
            if(ll%M[i]==0)d.PB(i+1);
        }
        printf("Case #%d: %d\n",case_n++,d[SZ(d)-(sum-N)-1]);
    }
    return 0;
}
