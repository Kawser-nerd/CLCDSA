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

const int N = 40;

int p3[N];

int n;
long long x[N],a[N],f;
vector<long long> S[N];

long long best;

void fun2(long long val, int step) {
    vector<long long>::iterator it;
    it = upper_bound(ALL(S[step]),f-val);
    if (it==S[step].begin()) return;
    it--;
    best = max(best, *it+val);
    
}

void fun(long long val, int step) {
    if (step > 1) fun2(val,step-1);
    fun2(val,step);
    fun2(val,step+1);
}

void single_case(int case_number) {
    
    best = -1;

    REP(i,N) S[i].clear();
    p3[0] = 1;
    for(int i=1;i<N;i++) p3[i] = p3[i-1]*3;

    scanf("%d",&n);
    REP(i,n) scanf("%lld",&x[i]);
    scanf("%lld",&f);
    sort(x,x+n);
    REP(i,n-1) a[i] = x[i+1]-x[i];
    REP(i,n-1) a[i] *= 2LL;
    n--;

    if (n==1) {
        printf("%lld\n",a[0]);
        return;
    }
    
    int l = n/2; 
    int r = n - l;
    
    REP(k,p3[l-1]) {
        long long val = 0;
        long long step = 1;
        bool ok = 1;
        REP(i,l) {
            val += (a[i]*step);
            if (i!=(l-1)) 
                step += (((k/p3[i])%3)-1);
            if (step<=0) { ok=0; break; }
        }
        if (ok) S[step].push_back(val);
    }

    REP(i,N) sort(ALL(S[i]));

    REP(k,p3[r-1]) {
        long long val = 0;
        long long step = 1;
        bool ok = 1;
        REP(i,r) {
            val += (a[n-1-i]*step);
            if (i!=(r-1)) 
                step += (((k/p3[i])%3)-1);
            if (step<=0) { ok=0; break; }
        }
        if (ok) fun(val, step);
    }

    if (best<0) printf("NO SOLUTION\n");
    else printf("%lld\n",best);
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

