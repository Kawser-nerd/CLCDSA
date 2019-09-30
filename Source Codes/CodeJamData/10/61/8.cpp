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

const int INF = 1<<20;
const int N = 128;

int n,dp[N][N][4];
char s[N];
const int BLANK = 3;

int f(int b, int e, int l) {
    if (dp[b][e][l]==NIL) {
        if (b==e) {
            dp[b][e][l] = 0;
            return 0;
        }
        if (s[b]==l) {
            dp[b][e][l] = (1+f(b+1,e,l));
            return dp[b][e][l];
        }
        int best = INF;
        for(int i=b+1;i<=e;i++)
            best = min(best, 2+f(b,i,s[b])+f(i,e,l));
        dp[b][e][l] = best;
        return best;
    } else
        return dp[b][e][l];
}

inline void single_case(int case_number) {
    scanf("%s",s);
    n = strlen(s);
    REP(i,n) s[i] -= 'A';
    REP(i,n+1) REP(j,n+1) REP(k,4) dp[i][j][k] = NIL;
    int result = f(0,n,BLANK);
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

