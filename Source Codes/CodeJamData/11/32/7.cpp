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
const int N=1<<20;
int l, n, c, a[1024];
PII am[1024];
long t, latest[N];
//count [0,last) % c == rem
int countrem(int last, int rem) {
	last-=rem+1;
	if (last<0) return 0;
	else return last/c+1;
}
long checksave(int start, int end, int left) {
	long ans=0;
	REP(i,c) {
		int rem=am[i].second;
		int cnt=countrem(end,rem)-countrem(start,rem);
		//cerr << start << " "<< end << " "<<  rem << " " << cnt << endl;
		checkmin(cnt,left);
		ans+=am[i].first*cnt;
		left-=cnt;
		if (left<=0) break;
	}
	//cerr << " " << start << " " << end << " " << left << " " << ans << endl;
	return ans;
}
long check(int loc, int left, long saved) {
	//cerr << loc << " "<< left << " "<< saved << endl;
	while (loc<n&&latest[loc+1]-saved<=t) ++loc;
	if (loc==n||left==0)return latest[n]-saved;
	//cerr << "  " << loc << " " <<latest[loc]  << " " << saved << " " << t << endl;
	if (latest[loc]-saved>=t) {
		return latest[n]-saved-checksave(loc,n,left);
	} else {
		long ans=check(loc+1, left, saved);
		long ans2=check(loc+1, left-1, saved+(latest[loc+1]-saved-t)/2);
		return min(ans,ans2);
	}
}
int main(int argc, char *argv[])
{
	//freopen("B2.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int test_case;
	scanf("%d", &test_case);
	for (int test_case_id=1; test_case_id<=test_case; ++test_case_id) {
		fprintf(stderr, "Case %d of %d\n", test_case_id, test_case);
		scanf("%d%ld%d%d", &l, &t, &n, &c);
		REP(i,c) scanf("%d", a+i); REP(i,c) am[i]=PII(a[i], i); sort(am, am+c, greater<PII>());
		latest[0]=0; REP(i,n) latest[i+1]=latest[i]+a[i%c]*2;
		long best=check(0, l, 0);
		printf("Case #%d: %ld\n", test_case_id, best);
	}
}
