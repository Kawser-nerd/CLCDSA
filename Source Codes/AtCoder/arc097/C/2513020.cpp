#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned long long
#define size(v) int((v).size())
#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#define rep(i, n) for (int i = 0; i < int(n); i++)
template<typename T>
inline void read(T &a) {
	register int b=1,c=getchar();a=0;
	for(;!isdigit(c);c=getchar())if(c==45)b*=-1;
	for(;isdigit(c);c=getchar())a=(a<<3)+(a<<1)+(c^48);
	a*=b;
}
// Template end

const int maxn = 4005;
char c[maxn][5];
int pos[2][maxn];
int dp[maxn][maxn];
int cost[maxn][maxn][2];
int n, a[maxn], tp[maxn];
int small[maxn][maxn][2];
int biger[maxn][maxn][2];

inline int MIN(const int &a, const int &b) { return a<b?a:b; }
inline int ABS(const int &a) { return a<0?-a:a; }

int main() {
	// freopen("input.txt","r",stdin);
	// Work start
	read(n);
	for(int i=1;i<=2*n;i++) {
		scanf("%s", c[i]);
		read(a[i]);
		if (c[i][0]=='B') tp[i]=1;
		pos[tp[i]][a[i]]=i;
	}
	for(int i=1;i<=2*n;i++) {
		if (i) for(int j=0;j<=n;j++) {
			small[i][j][0]=small[i-1][j][0];
			small[i][j][1]=small[i-1][j][1];
			biger[i][j][0]=biger[i-1][j][0];
			biger[i][j][1]=biger[i-1][j][1];
		}
		for(int j=0;j<a[i];j++) small[i][j][tp[i]]++;
		for(int j=a[i];j<=n;j++) biger[i][j][tp[i]]++;
	}
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) {
		if (i==n) continue;
		int nwpos=-1;
		if (pos[0][i+1]<=i+j) {
			nwpos=i+j+small[pos[0][i+1]][i][0]+small[pos[0][i+1]][j][1];
			eprintf("Case #1 : %d %d\n", small[pos[0][i+1]][i][0], small[pos[0][i+1]][j][1]);
		} else {
			nwpos=pos[0][i+1]+i-biger[pos[0][i+1]][i][0]+j-biger[pos[0][i+1]][j][1];
			eprintf("Case #2 : %d %d\n", biger[pos[0][i+1]][i][0], biger[pos[0][i+1]][j][1]);
		}
		eprintf("%d %d %d %d\n", i, j, pos[0][i+1], nwpos);
		cost[i][j][0]=nwpos-i-j-1;
		eprintf("%d %d %d\n", i, j, cost[i][j][0]);
	}
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) {
		if (j==n) continue;
		int nwpos=-1;
		if (pos[1][j+1]<=i+j) {
			nwpos=i+j+small[pos[1][j+1]][i][0]+small[pos[1][j+1]][j][1];
			eprintf("Case #1 : %d %d\n", small[pos[1][j+1]][i][0], small[pos[1][j+1]][j][1]);
		} else {
			nwpos=pos[1][j+1]+i-biger[pos[1][j+1]][i][0]+j-biger[pos[1][j+1]][j][1];
			eprintf("Case #2 : %d %d\n", biger[pos[1][j+1]][i][0], biger[pos[1][j+1]][j][1]);
		}
		eprintf("%d %d %d %d\n", i, j, pos[1][j+1], nwpos);
		cost[i][j][1]=nwpos-i-j-1;
		eprintf("%d %d %d\n", i, j, cost[i][j][1]);
	}
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) {
		if (!i && !j) continue;
		dp[i][j]=1000000007;
		if (i) dp[i][j]=MIN(dp[i][j],dp[i-1][j]+cost[i-1][j][0]);
		if (j) dp[i][j]=MIN(dp[i][j],dp[i][j-1]+cost[i][j-1][1]);
	}
	printf("%d\n",dp[n][n]);
#ifdef DEBUG
	printf("\nRunning Time : %ldms", clock());
#endif
	return 0;
} ./Main.cpp:28:2: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        register int b=1,c=getchar();a=0;
        ^~~~~~~~~
./Main.cpp:28:2: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        register int b=1,c=getchar();a=0;
        ^~~~~~~~~
2 warnings generated.