#include <cassert>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NIL = (-1);

typedef unsigned U;
typedef long long LL;
typedef long double LD;
typedef unsigned long long UL;

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<long long> VLL;
typedef pair<int,int> PII;

#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,b,e) for (int i=(b); i<=(e); i++)
#define FORD(i,b,e) for (int i=(b); i>=(e); i--)
#define FORALL(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FOREACH FORALL
#define SIZE(c) ((int)((c).size()))
#define LEN(c) ((int)((c).length()))
#define ALL(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define IT iterator
#define BC __builtin_popcount

const int N = 1024;
int n;
double R,x[N],y[N];

double dst(int i, int j) {
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int better(int i, int j, int k, double dir) {
    if (i==NIL) return j;
    assert(j!=NIL);
    double ai = atan2(y[i]-y[k],x[i]-x[k]);
    double aj = atan2(y[j]-y[k],x[j]-x[k]);
    if (ai<dir) ai += 1000.0;
    if (aj<dir) aj += 1000.0;
    if (ai<aj) return i;
    if (aj<ai) return j;
    if (dst(k,i) < dst(k,j)) return j; else return i;
}

int go(int k, double r, double dir) {
    //printf("go %d r=%lf\n",k,r);
    int best = NIL;
    REP(i,n) if (dst(i,k)<r && i!=k ) best = better(best, i, k, dir);
    if (best==NIL) return 0;
    return 1+go(best, r-dst(k,best), atan2(y[best]-y[k],x[best]-x[k]));
}



inline void single_case(int case_number) {
    scanf("%d",&n); scanf("%lf",&R);
    REP(i,n) scanf("%lf%lf",&x[i],&y[i]);
    int best = 0;
    for(double r=0.5;r<=R;r+=0.5) {
        //printf("r = %lf\n",r);
        best = max(best, go(0, r, atan2(-1,0)));
    }
    printf("%d\n",best);
}

int main() {
	int j = 1;
	scanf("%d",&j);//*/
	REP(i,j) {
        printf("Case #%d: ",1+i);   
        single_case(i);
    }
	return 0;
}

