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
int main(int argc, char *argv[])
{
	int n, k, b, t, x[64], v[64];
	bool valid[64];
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int test_case;
	scanf("%d", &test_case);
	for (int test_case_id=1; test_case_id<=test_case; ++test_case_id) {
		fprintf(stderr, "Case %d of %d\n", test_case_id, test_case);
		printf("Case #%d: ", test_case_id);
		cin>>n>>k>>b>>t;
		REP(i,n) cin>> x[i]; REP(i,n) cin>>v[i];
		REP(i,n) valid[i]=(x[i]+(LL)v[i]*t>=b);
		int nv=0; REP(i,n) if (valid[i]) ++nv;
		//if (k==0) cout << 0 << endl;
		if (nv<k) cout <<"IMPOSSIBLE" << endl;
		else {
			VI tt;
			REP(i,n) if (valid[i]) {
				int s=0;
				FOR(j,i+1,n-1) if (!valid[j]) ++s;
				tt.push_back(s);
			}
			sort(ALL(tt));
			int res=0;
			REP(i,k) res+=tt[i];
			cout << res << endl;
		}
	}
}

