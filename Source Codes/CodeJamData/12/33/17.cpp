#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long i64;

int T, N, M;
i64 a[100], A[100], b[100], B[100];
i64 dp[101][101];

i64 solve(int x, int y)
{
	if(x==0 || y==0) return 0;

	if(dp[x][y]==-1){
		dp[x][y] = max(solve(x-1, y), solve(x, y-1));
		if(A[x-1] == B[y-1]){
			i64 p=0, q;
			for(int i=x-1;i>=0;i--){
				if(A[i]==A[x-1]) p += a[i];
				q = 0;
				for(int j=y-1;j>=0;j--){
					if(B[j]==B[y-1]) q += b[j];
					dp[x][y] = max(dp[x][y], solve(i, j) + min(p, q));
				}
			}
		}
	}

	return dp[x][y];
}

int main()
{
	i64 p;
	int q;

	scanf("%d", &T);
	for(int t=0;t<T;){
		scanf("%d%d", &N, &M);

		for(int i=0;i<N;i++) scanf("%lld%lld", a+i, A+i);
		for(int i=0;i<M;i++) scanf("%lld%lld", b+i, B+i);

		for(int i=0;i<=N;i++)
			for(int j=0;j<=M;j++) dp[i][j] = -1;

		printf("Case #%d: %lld\n", ++t, solve(N, M));
	}
	return 0;
}
