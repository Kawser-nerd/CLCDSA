#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define REP(i,a,n) for (int i = (a); i < (n); i++)

template<class T> T& setmin(T &a, const T &b) {return a = min(a, b);}
template<class T> T& setmax(T &a, const T &b) {return a = max(a, b);}
template<class T> T MODD(const T &a, const T &b) {T r = a%b; if (r < 0) r += b; return r;}

int N;
char li[2000000];
int w[2000000];
int ne[2000000][10];
int pr[2000000][10];
int f[11000][11000];

void docase() {
	scanf("%s ", li);
	N = strlen(li);
	if (N <= 200000000) {
		REP(i,0,N)
			w[i] = li[i]-'0';
		REP(d,0,10) {
			ne[N][d] = N;
			pr[0][d] = 0;
		}
		for (int i = N-1; i >= 0; i--) {
			REP(d,0,10)
				ne[i][d] = ne[i+1][d];
			ne[i][w[i]] = i;
		}
		REP(i,1,N+1) {
			REP(d,0,10)
				pr[i][d] = pr[i-1][d];
			pr[i][w[i-1]] = i-1;
		}
	// 	printf("%d\n", ne[3][9]);
		for (int a = N; a >= 0; a--) {
			f[a][a] = 0;
			int c = a;
			REP(b,a+1,N+1) {
	// 			REP(d,0,10) {
	// 				int cs = ne[c+1][d];
				int be = 1000000000;
				while(true) {
					int cs = c+1;
					if (cs < b && max(f[a][cs],f[cs+1][b]) <= max(f[a][c],f[c+1][b])) {
						c = cs;
					} else
						break;
				}
				REP(d,0,10) {
					int q = pr[c][d];
	// 				printf("try %d\n", q);
					if (q >= a && q < b)
						setmin(be, w[q]+max(f[a][q],f[q+1][b]));
					q = ne[c][d];
	// 				printf("try %d\n", q);
					if (q >= a && q < b)
						setmin(be, w[q]+max(f[a][q],f[q+1][b]));
				}
// 				REP(q,a,b)
// 					setmin(be, w[q]+max(f[a][q],f[q+1][b]));
				f[a][b] = be;
	// 			f[a][b] = w[c]+max(f[a][c],f[c+1][b]);
	// 			printf("%d,%d => c=%d => %d\n", a, b, c, f[a][b]);
			}
		}
		printf("%d\n", f[0][N]);
	} else {
		printf("-1\n");
	}
}

int main() {
	int T;
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		docase();
		fflush(stdout);
		fflush(stderr);
	}
	return 0;
}
