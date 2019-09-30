#include <string>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cassert>
using namespace std;

/*PREWRITTEN CODE BEGINS HERE*/
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define SIZE(x) ( (int)((x).size()) )
#define CS c_str()
#define EL printf("\n")

#define ALL(v) (v).begin(), (v).end()
#define REP(i,n) for(int i=0,_n=(n); i<_n; ++i)
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; --i)
#define VAR(a,b) __typeof (b) a=b
#define FORE(i,a)  for(VAR(i,(a).begin()); i!=(a).end(); ++i)

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long long> VLL; 
typedef vector<vector<int> > VVI;
typedef vector<vector<string> > VVS;
/*PREWRITTEN CODE ENDS HERE*/
inline int RI() { int xx; scanf("%d",&xx); return xx; }
typedef long double LD;
const int INF = 1010000000;
const double EPS = 1e-9;
/*SOLUTION BEGINS HERE*/

char t[100][100];
void solve()
{
	int N, M;
	scanf("%d %d\n", &N, &M);
	REP(i, N) gets(t[i]);
	
	bool ok = true;
	REP(i, N) REP(j, M) if(t[i][j] == '#') {
		if(i + 1 >= N || j + 1 >= M) ok = false;
		if(t[i][j+1] != '#' || t[i+1][j] != '#' || t[i][j+1] != '#') ok = false;

		t[i][j] = '/'; t[i][j+1] = '\\';
		t[i+1][j] = '\\'; t[i+1][j+1] = '/';
	}

	if(!ok) {printf("Impossible\n"); return; }

	REP(i, N) puts(t[i]);
}

int main(void)
{
	int T = RI();
	FOR(i,1,T) {
		printf("Case #%d:\n", i);
        solve();
	}
	return (0);
}

