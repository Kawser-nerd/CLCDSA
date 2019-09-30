#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i=(a), _b=(b); i>=_b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define INF 1000000000
#define INF_LL 1000000000000000000LL
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int h = 111;

int n, w[h],l[h];
char s[h][h];
double wp[h], owp[h], oowp[h];

int main()
{
	freopen("a-large.in", "r", stdin); //-small-attempt
	freopen("a-large.out", "w", stdout); //-large
	int T, it=1;
for(scanf("%d", &T); it<=T; ++it)
{
	scanf("%d", &n);
	REP(i, n) scanf("%s", s[i]);
	CL(l, 0);
	CL(w, 0);
	REP(i, n) REP(j, n)
	{
		if(s[i][j]=='0') ++l[i];
		if(s[i][j]=='1') ++w[i];
	}
	REP(i, n)
	{
		wp[i] = double(w[i]) / (w[i]+l[i]);
		owp[i] = 0;
		REP(j, n) if(s[i][j]!='.')
		{
			if(s[i][j]=='1') owp[i] += double(w[j]) / (w[j]+l[j]-1);
			else owp[i] += double(w[j]-1) / (w[j]+l[j]-1);
		}
		owp[i] /= (w[i]+l[i]);
	}
	REP(i, n)
	{
		oowp[i] = 0;
		REP(j, n) if(s[i][j]!='.') oowp[i] += owp[j];
		oowp[i] /= (w[i]+l[i]);
	}
	printf("Case #%d:\n", it);
	//REP(i, n) printf("%.9lf %.9lf %.9lf\n", wp[i], owp[i], oowp[i]);
	REP(i, n) printf("%.9lf\n", 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]);
}
	return 0;
}
