#include <cstdio>
#include <cstring>

using namespace std;

const int T = 720;

int col[T*2+2];
int dp[2][T+2][T+2][2];
int ans;

int Min(int x, int y){
	return x < y ? x : y;
}

int main()
{
	freopen("b2.in", "r", stdin);
	freopen("b2.out", "w", stdout);
	int ts;
	scanf("%d", &ts);
	for (int t = 1; t <= ts; t ++)
	{
		//init
		int n, m;
		scanf("%d%d", &n, &m);
		memset(col, 0, sizeof(col));
		for (int i = 0; i < n; i ++){
			int c, d;
			scanf("%d%d", &c, &d);
			for (int j = c; j < d; j ++)
				col[j] = 1;
		}
		for (int i = 0; i < m; i ++){
			int c, d;
			scanf("%d%d", &c, &d);
			for (int j = c; j < d; j ++)
				col[j] = 2;
		}
		//dp
		for (int i = 0; i <= T; i ++)
			for (int j = 0; j <= T; j ++){
				dp[0][i][j][0] = dp[0][i][j][1] = T * 3;
				dp[1][i][j][0] = dp[1][i][j][1] = T * 3;
			}
		dp[0][0][0][0] = dp[1][0][0][1] = 0;
		for (int i = 0; i < T*2; i ++){
			for (int t1 = 0; t1 <= T && t1 <= i; t1 ++){
				int t2 = i - t1;
				if (t2 > T) continue;
				for (int w = 0; w < 2; w ++){
					if (!col[i]){
						dp[w][t1+1][t2][0] = Min(dp[w][t1+1][t2][0], Min(dp[w][t1][t2][0], dp[w][t1][t2][1]+1));
						dp[w][t1][t2+1][1] = Min(dp[w][t1][t2+1][1], Min(dp[w][t1][t2][0]+1, dp[w][t1][t2][1]));
					}
					else if (col[i] == 1){
						dp[w][t1][t2+1][1] = Min(dp[w][t1][t2+1][1], Min(dp[w][t1][t2][0]+1, dp[w][t1][t2][1]));
					} else {
						dp[w][t1+1][t2][0] = Min(dp[w][t1+1][t2][0], Min(dp[w][t1][t2][0], dp[w][t1][t2][1]+1));
					}
				}
			}
		}
		ans = Min(dp[0][T][T][0], dp[0][T][T][1] + 1);
		ans = Min(ans, Min(dp[1][T][T][1], dp[1][T][T][0] + 1));
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
