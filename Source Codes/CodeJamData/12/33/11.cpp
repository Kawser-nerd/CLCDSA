#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 111;

int task, cs=0;
long long dp[maxn][maxn], a[maxn], b[maxn], tempa[maxn], tempb[maxn];
int A[maxn], B[maxn],m, n;

int main() {
	freopen("C-large.in","r",stdin);
	freopen("a.out","w",stdout);

	for (scanf("%d", &task); task--;) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; i++) 
			scanf("%I64d%d", a+i, A+i);
		for (int i=0; i<m; i++) 
			scanf("%I64d%d", b+i, B+i);

		memset(dp, 0, sizeof(dp));
		for (int i=0; i<=n; i++)
		for (int j=0; j<=m; j++){
			memcpy(tempa, a, sizeof(a));
			memcpy(tempb, b, sizeof(b));
			if ( j + 1 <= m ) 
				dp[i][j+1] = max( dp[i][j],dp[i][j + 1] );

			if ( i + 1 <= n ){
				dp[i+1][j] = max( dp[i][j], dp[i + 1][j] );
				long long count = dp[i][j];
				int cur = A[i];

				for (int x = i, y = j; ; ) {
					while (x < n && A[x]!=cur) 
						x++;
					if (x >= n) break;

					while (y < m && B[y]!=cur) 
						y++;
					if (y >= m) break;

					if (tempa[x] == tempb[y]) {
						count += tempa[x];
						dp[x+1][y+1] = max(count, dp[x+1][y+1]);
						x++, y++;
					}else 
					if (tempa[x] < tempb[y]){
						count += tempa[x];
						tempb[y] -= tempa[x];
						dp[x+1][y+1] = max(count, dp[x+1][y+1]);
						x++;
					}else{
						count += tempb[y];
						tempa[x] -= tempb[y];
						dp[x+1][y+1] = max(count, dp[x+1][y+1]);
						y++;
					}
				}
			}
		}

		printf("Case #%d: %I64d\n", ++cs, dp[n][m]);
	}

	return 0;
}

