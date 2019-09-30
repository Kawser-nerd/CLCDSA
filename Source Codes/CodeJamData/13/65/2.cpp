#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
#include <cassert>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

int TT[10000];
int fact[10000];

inline bool conflict(int i, int j) {
    return (i - j) * (TT[i] - TT[j]) > 0;
}

vector<int> sub;

const int MOD = 10007;

int DP[200][200];

int T[150][1000];
int M;

void init(int N) {
     M = 1;
     while (M < N+1) M <<= 1;
     REP(i,N+1)REP(j,2*M) T[i][j] = 0;
}

void add(int l, int v, int a) {
    v += M;
    while (v) {
        T[l][v] = (T[l][v] + a) % MOD;
        v /= 2;    
    }
}

int get(int l, int A, int B, int v = 1, int L = 0, int R = M - 1) {
    if (A <= L && R <= B) return T[l][v];
    else if (R < A || B < L) return 0;
    
    return (get(l, A, B, 2 * v, L, (L+R)/2) + get(l, A, B, 2 * v + 1, (L+R)/2 + 1, R)) % MOD;
}


PII help[500];

void go() {
    int N = sub.size();

    REP(i,N) help[i] = PII(sub[i], -i);
    sort(help, help + N);
    REP(i,N) sub[-help[i].nd] = i;
    
    init(N);
    add(0,M-1,1);
    
    REP(i,N) {
        FORD(j,N+1, 1) {        
            int cnt = get(j-1, sub[i], M-1);
            add(j, sub[i], cnt);        
        }
    }
}

void scase() {
    int N;
    scanf("%d",&N);
    REP(i,N) scanf("%d",&TT[i]);
    
    bool any = false;
    REP(i,N-1) if (TT[i] < TT[i+1]) any = true;
    if (!any) {
        printf("1\n");
        return;
    }

    int result = 0;
    REP(i,N)REP(j,N) {
        if (!conflict(i,j)) continue;
        
        sub.clear();
        REP(k,N) {
            if (k < j && conflict(i,k)) continue;
            if (conflict(k,j)) continue;
            if (k == j) continue;
            
            sub.push_back(TT[k]);
        }
        
        go();        
        
        REP(k,sub.size()+1) {
            result = (result + fact[N - k - 2] * get(k, 0, M - 1)) % MOD;
        }
    }
    
    printf("%d\n", result);
}

int main() {
    fact[0] = 1;
    FOR(i,1,10000) fact[i] = fact[i-1] * i % 10007;

    int C;
    scanf("%d",&C);
    FOR(i,1,C+1) {
        printf("Case #%d: ", i);
        scase();
    }
}  
