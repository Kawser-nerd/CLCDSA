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

const int h=200;
int t, p,q, a[h];
int d[h][h];

int main()
{
freopen("c-large.in", "r", stdin);
freopen("c-large.out", "w", stdout);
	scanf("%d", &t);
	REP(it, t)
	{
		scanf("%d%d", &p, &q);
		++q;
		FOR(i, 1, q) scanf("%d", &a[i]);
		a[0]=0; a[q]=p+1;
		REP(i, q) d[i][i+1]=0;
		FOR(k, 2, q+1) REP(i, q-k+1)
		{
			d[i][i+k]=p*q;
			FOR(j, i+1, i+k) d[i][i+k]=min(d[i][i+k], d[i][j]+d[j][i+k]);
			d[i][i+k]+=a[i+k]-a[i]-2;
		}
		printf("Case #%d: %d\n", it+1, d[0][q]);
	}	
	return 0;
}
