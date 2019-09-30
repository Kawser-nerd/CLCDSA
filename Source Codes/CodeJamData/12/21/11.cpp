#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b);i>=(e);--i)
#define FOReach(it,V) for(__typeof((V).begin()) it=(V).begin();it!=(V).end();++it)

#define PB push_back
#define ALL(V) (V).begin(),(V).end()
#define SIZE(V) ((int)(V).size())

#define MP make_pair
#define ST first
#define ND second

#define DBG

#ifdef DBG
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

int stmp;
#define scanf stmp=scanf


const int MAX = 200;
const int INF = 1000000001;
const double EPS = 1e-9;

int s[MAX];
int S;

int n;

double solve(int x) {
	double p = 0.0, q = 1.0;
	REP(foo,120)
	{
		double r = (p+q)/2.0;
		double pt = (double)s[x] + (double)S*r;
		double sum = r;
		REP(i,n)
			if(i != x && s[i] < pt)
				sum += ((double)pt-s[i])/(double)S;
		if(sum < 1.0)
			p = r;
		else
			q = r;
	}
	return ((p+q)/2.0)*100.0;
}

int main(int argc, char *argv[]) {
	int Z;
	scanf("%d", &Z);
	FOR(z,1,Z)
	{
		printf("Case #%d:", z);
		scanf("%d", &n);
		S = 0;
		REP(i,n)
		{
			scanf("%d", s+i);
			S += s[i];
		}
		REP(i,n)
			printf(" %.9lf", solve(i));
		printf("\n");
	}
	return 0;
}

