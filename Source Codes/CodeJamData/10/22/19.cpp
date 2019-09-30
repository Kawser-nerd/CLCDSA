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

int n,k, b, t;
const int h=100;
int x[h], v[h];

int main()
{
#ifdef LocalHost
freopen("b-large.in", "r", stdin);//-small-attempt
freopen("b-large.out", "w", stdout);//-large
#endif
	int T;
	scanf("%d", &T);
REP(it, T)
{
	scanf("%d%d%d%d", &n, &k, &b, &t);
	REP(i, n) scanf("%d", &x[i]);
	REP(i, n) scanf("%d", &v[i]);
	int ans = 0;
	for(int i=n-1; i>=0; --i)
	{
		if(k<=0) break;
		if(b-x[i] <= ll(t)*v[i]) --k;
		else ans += k;
	}
	printf("Case #%d: ", it+1);
	if(k>0) printf("IMPOSSIBLE\n");
	else printf("%d\n", ans);
}
	return 0;
}
