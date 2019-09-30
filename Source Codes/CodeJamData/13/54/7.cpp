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

char S[1000];
double DP[30][1<<20];

int nxt[50];
void scase() {
    scanf("%s",S);

    int N = strlen(S);    
    int mask = 0;
    int K = 0;
    REP(i,N) if (S[i] == 'X') {
        ++K;
        mask |= (1<<i);
    }
    
    REP(i,1<<20) DP[0][i] = 0;
    DP[0][mask] = 1;
    
    K = N - K;
    
    double result = 0.0;
    FOR(i,1,K+1) {
        REP(m,1<<N) DP[i][m] = 0;
        REP(m,1<<N) {
            if (DP[i-1][m] < 1e-10) continue;        
        
            int t = -1;
            FORD(x,N,0) {
                if (!(m&(1<<x))) t = x;            
                nxt[x] = t;
            }
            FORD(x,N,0) {
                if (!(m&(1<<x))) t = x;
                nxt[x] = t;                
            }            
        
            REP(x,N) {
                int waiting = (nxt[x] - x + N) % N;
                result += DP[i-1][m] * 1.0 / N * (N - waiting);
                
                //printf("%d %d %d\n",i,m,waiting);
                //printf("%d %d\n",x,nxt[x]);
                DP[i][m|(1<<nxt[x])] += DP[i-1][m] / N;
            }
        }
        //printf("!!%lf\n", result);
    }
    
    printf("%0.10lf\n", result);
}

int main() {
    int C;
    scanf("%d",&C);
    FOR(i,1,C+1) {
        printf("Case #%d: ", i);
        scase();
    }
}  
