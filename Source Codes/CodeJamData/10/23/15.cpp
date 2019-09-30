#include <string>
#include <cctype>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <iostream>
#include <sstream>
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
#define CLR(c,n) memset(c,n,sizeof(c))
#define TR(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define CONTAIN(container, it) (container.find(it)!=container.end())
#define CLR(container, val) memset(container, val, sizeof(container))
#define MCPY(dest,src) memcpy(dest,src,sizeof(src))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;
const double EPS=1e-9;
const double PI=acos(-1);
const int INF=0x3F3F3F3F;
const int MOD=100003;
int cnt[512][512], C[500][500], res[512];
int main(int argc, char *argv[])
{
	FOR(i,0,500) {
		C[i][0]=C[i][i]=1;
		FOR(j,1,i-1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	FOR(i,2,500) {
		cnt[i][1]=1;
		FOR(j,2,i-1) {
			FOR(k,1,j-1) cnt[i][j]=(cnt[i][j]+(LL)cnt[j][k]*C[i-j-1][j-k-1])%MOD;
		}
		res[i]=0;
		FOR(j,1,i-1) res[i]=(res[i]+cnt[i][j])%MOD;
	}
	freopen("C-large.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int test_case;
	scanf("%d", &test_case);
	for (int test_case_id=1; test_case_id<=test_case; ++test_case_id) {
		fprintf(stderr, "Case %d of %d\n", test_case_id, test_case);
		printf("Case #%d: ", test_case_id);
		int n; cin>>n; cout << res[n] << endl;
	}
}

