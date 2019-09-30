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
const int SIZE = 155;
long long a[SIZE],b[SIZE],d[SIZE];
int cs;
int cnt(long long x){
    if(!x)return 0;
    return (x&1)+cnt(x>>1);
}
int main(){
    int T,i,j,k,n;
    CASET{
        MS0(a);
        MS0(b);

        DRII(N,L);
        REP(i,N){
            char s[44];
            RS(s);
            REP(j,L)a[i]|=((long long)(s[j]-'0')<<j);
        }
        REP(i,N){
            char s[44];
            RS(s);
            REP(j,L)b[i]|=((long long)(s[j]-'0')<<j);
        }
        sort(b,b+N);
        int an=L*2;
        REP(i,N){
            long long need = a[0]^b[i];
            REP(j,N)d[j]=a[j]^need;
            sort(d,d+N);
            bool suc=true;
            REP(j,N){
                if(d[j]!=b[j]){
                    suc=false;
                    break;
                }
            }
            if(suc)an=min(an,cnt(need));
        }
        printf("Case #%d: ",case_n++);
        if(an<=L)printf("%d\n",an);
        else puts("NOT POSSIBLE");
    }
    return 0;
}

