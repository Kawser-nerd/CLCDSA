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
int cs,score[1000][1000],d[1000];
long long myrand(){
    return ((long long)rand()<<10)^rand();
}
int main(){
    /*srand(514);
    for(int i=0;i<1000000;i++){
        REP(j,1000)d[j]=j;
        REP(j,1000)swap(d[j],d[myrand()%1000]);
        REP(j,1000)score[j][d[j]]++;
    }
    REP(i,1000){
        REP(j,1000)printf("%d ",score[i][j]);
        puts("");
    }*/
    FILE *fptr;
    fptr=fopen("record.txt","r");
    REP(i,1000)REP(j,1000)fscanf(fptr,"%d",&score[i][j]);
    fclose(fptr);
    CASET{
        DRI(n);
        long double res=1;
        REP(i,n){
            DRI(x);
            res*=score[i][x]*0.001;
        }
        printf("Case #%d: ",case_n++);
        if(res>=1)puts("BAD");
        else puts("GOOD");
    }
    return 0;
}

