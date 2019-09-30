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


const int MAX = 500;
const int INF = 1000000001;

LL tab[MAX];

int n;

void print(LL mask) {
	REP(i,n)
		if(mask & (1LL<<i))
			printf("%lld ", tab[i]);
	printf("\n");
}

int main(int argc, char *argv[]) {
	srand(1337);
	int Z;
	scanf("%d", &Z);
	FOR(z,1,Z)
	{
		printf("Case #%d:\n", z);
		scanf("%d", &n);
		REP(i,n)
			scanf("%lld", tab+i);
		n = 50;
		map<LL,LL> M;
		bool found = false;
		while(!found)
		{
			LL mask = 0;
			LL s = 0;
			REP(i,n)
				if(rand()&1) {
					s += tab[i];
					mask |= (1LL<<i);
					LL ms = M[s];
					if(ms && mask != ms) {
						print(mask);
						print(ms);
						found = true;
						break;
					}
					if(ms != mask)
						M[s] = mask;
				}
		}
		fflush(stdout);
	}
	return 0;
}

