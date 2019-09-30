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

int main(void) {
	int T; scanf("%d", &T);
	REP(t,T) {
		int n, sum=0, x=0, mn=1000000000; scanf("%d", &n);
		REP(i,n) {
			int a; scanf("%d", &a);
			sum+=a; x^=a;
			mn=min(mn, a);
		}
		if(x)
			printf("Case #%d: NO\n", t+1);
		else
			printf("Case #%d: %d\n", t+1, sum-mn);
	}
	return 0;
} 
