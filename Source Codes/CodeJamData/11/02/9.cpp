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

int opp[310][310], com[310][310];
char buf[110];

int main(void) {
	int T; scanf("%d", &T);
	REP(t,T) {
		memset(opp, 0, sizeof opp);
		memset(com, 0, sizeof com);
		int a; scanf("%d", &a);
		REP(i,a) {
			scanf("%s", buf);
			com[buf[0]][buf[1]]=com[buf[1]][buf[0]]=buf[2];
		}
		scanf("%d", &a);
		REP(i,a) {
			scanf("%s", buf);
			opp[buf[0]][buf[1]]=opp[buf[1]][buf[0]]=1;
		}
		int n; scanf("%d%s", &n, buf);
		vector<int> res;
		REP(i,n) {
			int x=buf[i], y;
			if(!res.empty())
				y=res.back();
			else {
				res.PB(x);
				continue;
			}
			if(com[x][y]!=0) {
				res.pop_back();
				res.PB(com[x][y]);
			}
			else {
				res.PB(x);
				REP(j,SZ(res)-1) {
					if(opp[x][res[j]]) {
						res.clear();
						break;
					}
				}
			}
		}
		printf("Case #%d: [", t+1);
		REP(i,SZ(res)) {
			if(i>0)
				printf(", ");
			printf("%c", res[i]);
		}
		puts("]");
	}
	return 0;
}
