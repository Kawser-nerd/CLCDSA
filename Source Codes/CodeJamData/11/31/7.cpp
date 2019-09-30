#include <string>
#include <cctype>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <memory.h>
#include <assert.h>
using namespace std;
#define SZ(a) (int)(a).size()
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define REP(i,n) for (int i=0; i<(n); ++i)
#define ALL(c) c.begin(), c.end()
#define TR(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define CONTAIN(container, it) (container.find(it)!=container.end())
#define CLR(c,n) memset(c,n,sizeof(c))
#define MCPY(dest,src) memcpy(dest,src,sizeof(src))
template<class T> T checkmax(T &a, T b) {return a=max(a,b);}
template<class T> T checkmin(T &a, T b) {return a=min(a,b);}
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;
const double EPS=1e-9;
const double PI=acos(-1);
const int INF=0x3F3F3F3F;
int r, c;
char g[64][64];
int main(int argc, char *argv[])
{
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int test_case;
	scanf("%d", &test_case);
	for (int test_case_id=1; test_case_id<=test_case; ++test_case_id) {
		//fprintf(stderr, "Case %d of %d\n", test_case_id, test_case);
		scanf("%d%d", &r, &c);
		CLR(g,0);
		REP(i,r) scanf("%s", g[i]);
		bool valid=true;
		REP(i,r) REP(j,c) if (g[i][j]=='#') {
			if (g[i+1][j]=='#'&&g[i][j+1]=='#'&&g[i+1][j+1]=='#') {
				g[i][j]=g[i+1][j+1]='/';
				g[i+1][j]=g[i][j+1]='\\';
			} else valid=false;
		}
		printf("Case #%d:\n", test_case_id);
		if (valid) {
			REP(i,r) printf("%s\n", g[i]);
		} else printf("Impossible\n");
	}
}
