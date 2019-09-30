#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

double e[1010]; int vis[1010], perm[1010];

int main(void) {
	e[1]=0.0; double sum=0.0;
	FOR(i,2,1001) {
		e[i]=((1.0+sum)*(0.0+i))/(-1.0+i);
		sum+=e[i]/i;
	}
	int T; scanf("%d", &T);
	REP(t,T) {
		int n; scanf("%d", &n);
		REP(i,n) {
			scanf("%d", &perm[i]);
			--perm[i];
		}
		memset(vis, 0, sizeof vis);
		double res=0.0;
		REP(i,n) {
			if(vis[i])
				continue;
			int k=0, j=i;
			while(!vis[j]) {
				++k;
				vis[j]=1;
				j=perm[j];
			}
			res+=e[k];
		}
		printf("Case #%d: %lf\n", t+1, res);
	}
	return 0;
}
