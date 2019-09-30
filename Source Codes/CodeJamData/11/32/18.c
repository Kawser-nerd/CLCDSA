#include <stdio.h>

long long min(long long a, long long b)
{
	if (a < b)
		return a;
	return b;
}

long long max(long long a, long long b)
{
	if (a > b)
		return a;
	return b;
}

void solveCase()
{
	long long dist[1000];
	int C, L, N;
	long long t;
	int i,j,R;
	long long dp[1000][3];
	
	scanf("%d %lld %d %d", &L, &t, &N, &C);
	
	for (i=0; i<C; i++)
	{
		scanf("%d", &R);
		for (j=0; j*C+i<N; j++)
		{
			dist[j*C+i] = R;
		}
	}
	
	dp[0][0] = 2*dist[0];
	dp[0][2] = dp[0][1] = min(dp[0][0], t+max(0, dist[0]-t/2));
	
	for (i=1; i<N; i++)
	{
		dp[i][0] = dp[i-1][0] + 2*dist[i];
		dp[i][1] = min(dp[i][0], min(dp[i-1][0] + max(0, t-dp[i-1][0]) + max(0, dist[i]-max(0,t-dp[i-1][0])/2), dp[i-1][1]+2*dist[i]));
		dp[i][2] = min(dp[i][0], min(dp[i-1][1] + max(0, t-dp[i-1][1]) + max(0, dist[i]-max(0,t-dp[i-1][1])/2), dp[i-1][2]+2*dist[i]));
	}
	
	printf("%lld\n", dp[N-1][L]);
}

int main()
{
	int T, i;
	
	scanf("%d", &T);
	
	for (i=0; i<T; i++)
	{
		printf("Case #%d: ", i+1);
		solveCase();
	}
	
	return 0;
}
