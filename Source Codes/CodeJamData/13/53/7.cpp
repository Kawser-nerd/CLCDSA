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

int roads[50][4];
int path[50];

list<PII> adj1[50];
list<PII> adj2[50];

int D1[50];
int D2[50];

void scase() {
    int N,M,P;
    scanf("%d%d%d",&N,&M,&P);
    REP(i,M) {
        REP(j,4) scanf("%d",&roads[i][j]);
        roads[i][0]--;
        roads[i][1]--;
    }
    REP(i,P) {
        scanf("%d",&path[i]);
        --path[i];
    }
    
    int bst = -1;
    REP(m,1<<M) {
        REP(i,N) adj1[i].clear();
        REP(i,N) adj2[i].clear();
        
        REP(j,M) {
            int d = (m&(1<<j)) ? roads[j][3] : roads[j][2];
            adj1[roads[j][0]].push_back(PII(roads[j][1],d));        
            adj2[roads[j][1]].push_back(PII(roads[j][0],d));                    
        }

        priority_queue<PII, vector<PII>, greater<PII> > Q;
            
        REP(i,N) D1[i] = 999999999;
        D1[0] = 0;
        Q.push(PII(0,0));
        while (!Q.empty()) {
            int v = Q.top().nd;
            int d = Q.top().st;
            Q.pop();
            if (D1[v] < d) continue;
        
            FOREACH(it, adj1[v]) {
                if (D1[it->st] <= D1[v] + it->nd) continue;
                D1[it->st] = D1[v] + it->nd;
                Q.push(PII(D1[it->st], it->st));            
            }        
        }
        
        REP(i,N) D2[i] = 999999999;
        D2[1] = 0;
        Q.push(PII(0,1));
        while (!Q.empty()) {
            int v = Q.top().nd;
            int d = Q.top().st;
            Q.pop();
            if (D2[v] < d) continue;
        
            FOREACH(it, adj2[v]) {
                if (D2[it->st] <= D2[v] + it->nd) continue;
                D2[it->st] = D2[v] + it->nd;
                Q.push(PII(D2[it->st], it->st));            
            }        
        }
        
        int my = 0;
        REP(i,P) {
            int j = path[i];
            int d = (m&(1<<j)) ? roads[j][3] : roads[j][2];            
            my += d;
            
            int v = roads[j][1];
            if (my == D1[v] && D1[v] + D2[v] == D1[1]) bst = max(bst, i);        
        }
    }
    
    if (bst == P-1) {
        printf("Looks Good To Me\n");
    } else printf("%d\n", path[bst+1] + 1);

}

int main() {
    int C;
    scanf("%d",&C);
    FOR(i,1,C+1) {
        printf("Case #%d: ", i);
        scase();
    }
}  
