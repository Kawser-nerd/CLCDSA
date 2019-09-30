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

LL X[200];

void scase() {
    LL B;
    int N;
    scanf("%lld%d",&B,&N);
    REP(i,N) scanf("%lld",&X[i]);
    FOR(i,N,37) X[i] = 0;
    N = 37;
    
    sort(X, X+N);
    double result = 0.0;
    REP(i,N-1)FOR(j,i,N-1) {
        if (X[j+1] == X[j]) continue;
        LL Q = X[j] == X[i] ? X[j] + 1 : X[j];
    
        LL needed = 0;
        LL needed2 = 0;
                
        REP(k,i+1) needed += (Q-1) - X[k];
        FOR(k,i+1,j+1) needed2 += Q - X[k];
        
        if (needed + needed2 > B) continue;
    
        LL add = (B - needed - needed2) / (j + 1);
        add = min(add, X[j+1] - Q);
        
        LL stake = needed + needed2 + add * (j + 1);
        LL winning = needed + add * (i + 1);
        
        result = max(result, winning * 36.0 / (i + 1) - stake);    
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
