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

double T[100000];

int ord[100000];
void scase() {
    int N;
    scanf("%d",&N);
    REP(i,N) scanf("%lf", &T[i]);
    
    double result = T[N-1] - T[0];
    
    REP(i,N) ord[i] = i;
    random_shuffle(ord, ord + N);
    
    REP(q,N) {
        int i = ord[q];
    
        double MAXK = T[N-1] - T[0], MINK = 0.0;
        REP(j,N) {
            if (i == j) continue;
            if (i < j) MAXK = min(MAXK, (T[j] - T[i]) / (j - i));           
            else MINK = max(MINK, (T[j] - T[i]) / (j - i));
        }
        
        if (MINK > MAXK) continue;

        double EPS = 0.0;
        REP(j,N) EPS = max(EPS, min(T[j] - T[i] - (j-i) * MINK,
                                    T[j] - T[i] - (j-i) * MAXK));
                                    
        if (EPS > result - 1e-9) continue;

        double LEPS, REPS;
        REP(k,100) {        
            double L = (2 * MINK + MAXK) / 3.0;
            double R = (2 * MAXK + MINK) / 3.0;
            
            LEPS = 0.0, REPS = 0.0;
            REP(j,N) {
                if (i == j) continue;
                LEPS = max(LEPS, T[j] - T[i] - (j-i) * L);            
                REPS = max(REPS, T[j] - T[i] - (j-i) * R);                                        
            }
        
            if (REPS > LEPS) MAXK = R;
            else MINK = L;
        }

        result = min(result, LEPS);
    }
    
    printf("%0.6lf\n", result / 2);
}

int main() {
    int C;
    scanf("%d",&C);
    FOR(i,1,C+1) {
        printf("Case #%d: ", i);
        scase();
    }
}  
