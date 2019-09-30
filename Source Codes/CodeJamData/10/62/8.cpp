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

const int N = 1111;

int n,dp[N][N],dp2[N][N];
VI g[N][N];

int go(int a, int b) {
    if (a>b) return go(b,a);
    if (dp[a][b]!=NIL) return dp[a][b];
    vector<int> v;
    int best = 0;
    FOREACH(i,g[a][b])
        v.pb(1+go(a,*i)+go(*i,b));
    sort(ALL(v)); reverse(ALL(v));
    if (SIZE(v)==0) { dp[a][b] = dp2[a][b] = 0; }
    if (SIZE(v)==1) { dp[a][b] = dp2[a][b] = v[0]; }
    if (SIZE(v)>1) {
        dp[a][b] = v[0];
        dp2[a][b] = v[0] + v[1];
    }
    return dp[a][b];
}

inline void single_case(int case_number) {
    scanf("%d",&n);
    REP(i,n) REP(j,n) g[i][j].clear();
    
    /*printf("\n");
    printf("N = %d\n",n); // */

    REP(i,n-3) {
        int a,b;
        scanf("%d%d",&a,&b);

        //printf("%d %d\n",a,b); // */

        a--; b--;
        if (a>b) swap(a,b);
        g[a][b].pb(i+3);
    }
    REP(i,n) REP(j,n) dp[i][j] = dp2[i][j] = NIL;
    int result = 3+go(0,1)+go(1,2)+go(2,0);
    REP(i,n) REP(j,n) if (dp2[i][j]!=NIL)
        result = max(result, 2+dp2[i][j]);
    printf("%d\n",result);
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

