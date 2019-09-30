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

int kto[110]; char buf[10];

int main(void) {
	int T; scanf("%d", &T);
	REP(t,T) {
		int n; scanf("%d", &n);
		VI a[2]; int g[2], res=0;
		REP(i,n) {
			int x; scanf("%s%d", buf, &x);
			if(buf[0]=='O') {
				a[0].PB(x);
				kto[i]=0;
			}
			else {
				a[1].PB(x);
				kto[i]=1;
			}
		}
		REP(i,2) {
			reverse(ALL(a[i]));
			g[i]=1;
		}
		for(int i=0; i<n; ++res) {
			int x=kto[i], y=1-x;
			if(!a[y].empty()) {
				if(g[y]<a[y].back())
					++g[y];
				else if(g[y]>a[y].back())
					--g[y];
			}
			if(g[x]==a[x].back()) {
				++i;
				a[x].pop_back();
			}
			else if(g[x]<a[x].back())
				++g[x];
			else
				--g[x];
		}
		printf("Case #%d: %d\n", t+1, res);
	}
	return 0;
}
			
