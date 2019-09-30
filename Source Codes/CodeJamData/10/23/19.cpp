#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define UN(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b) memset(a,b,sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int mod = 100003, h=1000;
int mul (int a, int b) { return (ll(a)*b) % mod; }

int n;

int ff[h][h], cc[h][h];

int c (int n, int k)
{
	if(k>n || k<0) return 0;
	if(n==0) return 1;
	if(cc[n][k]!=-1) return cc[n][k];
	return cc[n][k] = (c(n-1, k-1) + c(n-1, k)) % mod;
}

int f (int n, int k)
{
	if(k==1) return 1;
	if(ff[n][k]!=-1) return ff[n][k];
	int &r = ff[n][k];
	r = 0;
	FOR(i, 1, k) r = (r + mul(f(k, i), c(n-k-1, k-i-1))) % mod;
	return r;
}

int main()
{
#ifdef LocalHost
freopen("c-large.in", "r", stdin);//-small-attempt
freopen("c-large.out", "w", stdout);//-large
#endif
	int T;
	scanf("%d", &T);
	CL(ff, -1);
	CL(cc, -1);
REP(it, T)
{
	scanf("%d", &n);
	int ans = 0;
	FOR(i, 1, n) ans = (ans + f(n, i)) % mod;
	printf("Case #%d: %d\n", it+1, ans);
}
	return 0;
}
