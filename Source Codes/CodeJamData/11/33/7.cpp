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
typedef pair<long, int> PII;
const double EPS=1e-9;
const double PI=acos(-1);
const int INF=0x3F3F3F3F;
const int MAXP=100000000;
int n;
const int N=10001;
long l, h, f[N], g;
bool isprime[MAXP];
vector<PII> fac;
long check(int id, long cur) {
	if (cur>h) return -1;
	if (id==fac.size()) {
		if (cur<l) return -1;
		return cur;
	}
	long ans=check(id+1,cur);
	REP(i,fac[id].second) {
		cur*=fac[id].first;
		long p=check(id+1,cur);
		if (p==-1) continue;
		if (ans==-1||p<ans) ans=p;
	}
	return ans;
}
void fact(long g) {
	fac.clear();
	for (long i=2; i*i<=g; ++i) if (isprime[i]&&g%i==0) {
		int cnt=0;
		while (g%i==0) g/=i, ++cnt;
		fac.push_back(PII(i,cnt));
	}
	if (g!=1) fac.push_back(PII(g,1));
}
long gcd(long a, long b) {return a?gcd(b%a,a):b;}
long bound[N];
int main(int argc, char *argv[])
{
	freopen("C-large.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int test_case;
	CLR(isprime,true); isprime[0]=isprime[1]=false;
	for (int i=2; i*i<MAXP; ++i) if (isprime[i]) for (int j=i*i; j<MAXP; j+=i) isprime[j]=false;
	scanf("%d", &test_case);
	for (int test_case_id=1; test_case_id<=test_case; ++test_case_id) {
		fprintf(stderr, "Case %d of %d\n", test_case_id, test_case);
		printf("Case #%d: ", test_case_id);
		scanf("%d%ld%ld", &n, &l, &h); REP(i,n) scanf("%ld", &f[i]);
		sort(f,f+n);
		bound[n]=0;
		for (int i=n-1; i>=0; --i) bound[i]=gcd(bound[i+1], f[i]);
		long best=-1;
		long lcm=1;
		REP(i,n) if (best==-1) {
			if (lcm<=h&&bound[i]>=l&&bound[i]%lcm==0) {
				fact(bound[i]/lcm);
				best=check(0,lcm);
			}
			lcm/=gcd(lcm,f[i]);
			if (h/lcm<f[i]) {
				if (best==-1) best=-2;
				break;
			}
			lcm*=f[i];
		}
		if (best==-1&&lcm<h) {
			long p=l/lcm*lcm;
			if (p<l) p+=lcm;
			if (p<=h) best=p;
		}
		if (best>0) printf("%ld\n", best);
		else printf("NO\n");
	}
}
