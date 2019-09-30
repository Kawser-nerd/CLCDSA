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

int T[200000][4];
int prev[200000][4]; // poprzedni, ktory nie mial tej liczby
int next[200000][4];

inline PII better(PII a, PII b) {
    if (a.nd - a.st > b.nd - b.st) return a;
    if (a.nd - a.st < b.nd - b.st) return b;    
    return a.st < b.st ? a : b;
}

void scase() {
    int N, D, K;
    scanf("%d%d%d",&N,&D,&K);
    REP(i,N)REP(j,D) scanf("%d", &T[i][j]);
    
    REP(i,N) {
        REP(j,D) {
            bool found = false;
            if (i > 0) {
                REP(k,D) if (T[i-1][k] == T[i][j]) {
                    prev[i][j] = prev[i-1][k];
                    found = true;
                }
            }
            
            if (!found) prev[i][j] = i - 1;
        }
    }
    
    FORD(i,N,0) {
        REP(j,D) {
            bool found = false;
            if (i < N - 1) {
                REP(k,D) if (T[i+1][k] == T[i][j]) {
                    next[i][j] = next[i+1][k];
                    found = true;
                }
            }
            
            if (!found) next[i][j] = i + 1;
        }    
    }
    
    PII result(0,0);
    
    REP(i,N)REP(j,D) {
        result = better(result, PII(prev[i][j] + 1, next[i][j] - 1));    
    }
       
    map<PII, int> last;
    
    REP(i,N-1) REP(j,D) REP(k,D) {
        int A = T[i][j], B = T[i+1][k];
        if (A == B) continue;
        
        int LA = prev[i][j], LB = prev[i+1][k];        
        int RA = next[i][j], RB = next[i+1][k];
                
        //if (A > B) swap(A,B);
    
        if (last.find(PII(A,B)) != last.end() && last[PII(A,B)] >= i) continue;
    
        while (true) {
            if (LA == LB) break;
            else if (LA < LB && LA >= 0) {
                bool xx = false;
                REP(w,D) if (T[LA][w] == B) {
                    LB = prev[LA][w];
                    xx = true;                
                }
                if (!xx) break;
            } else if (LB < LA && LB >= 0){
                bool xx = false;
                REP(w,D) if (T[LB][w] == A) {
                    LA = prev[LB][w];
                    xx = true;                
                }
                if (!xx) break;                        
            } else break;       
        }
        
        while (true) {
            if (RA == RB) break;
            else if (RA > RB && RA <= N-1) {
                bool xx = false;
                REP(w,D) if (T[RA][w] == B) {
                    RB = next[RA][w];
                    xx = true;                
                }
                if (!xx) break;
            } else if (RB > RA && RB <= N-1){
                bool xx = false;
                REP(w,D) if (T[RB][w] == A) {
                    RA = next[RB][w];
                    xx = true;                
                }
                if (!xx) break;                        
            } else break;       
        }        
        
        result = better(result, PII(min(LA,LB)+1, max(RA,RB)-1));
        last[PII(A,B)] = max(RA,RB);
    }
    
    printf("%d %d\n", result.st, result.nd);
}

int main() {
    int C;
    scanf("%d",&C);
    FOR(i,1,C+1) {
        printf("Case #%d: ", i);
        scase();
    }
}  
