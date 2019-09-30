#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 500 + 10;

int n,m,D;

int a[maxn][maxn];
long long sum[maxn][maxn],Xsum[maxn][maxn],Ysum[maxn][maxn];


inline long long subsum( long long sum[maxn][maxn],int x1,int x2,int y1,int y2 )
{
	return sum[x2][y2] + sum[x1-1][y1-1] - sum[x2][y1-1] - sum[x1-1][y2];
}
bool good( int K )
{
	int midX,midY;
	for( int i = 1;i+K-1<=n;i++ )
	for( int j = 1;j+K-1<=m;j++ )
	{
		midX = i + (i+K-1) - 1;
		midY = j + (j+K-1) -1;
		if( subsum(Xsum,i,i+K-1,j,j+K-1) - subsum(Xsum,i,i,j,j) - subsum(Xsum,i+K-1,i+K-1,j+K-1,j+K-1) - subsum(Xsum,i+K-1,i+K-1,j,j) - subsum(Xsum,i,i,j+K-1,j+K-1) == midX * (subsum(sum,i,i+K-1,j,j+K-1)-subsum(sum,i,i,j,j) - subsum(sum,i+K-1,i+K-1,j+K-1,j+K-1) - subsum(sum,i+K-1,i+K-1,j,j) - subsum(sum,i,i,j+K-1,j+K-1))
			&& subsum(Ysum,i,i+K-1,j,j+K-1) - subsum(Ysum,i,i,j,j) - subsum(Ysum,i+K-1,i+K-1,j+K-1,j+K-1) - subsum(Ysum,i+K-1,i+K-1,j,j) - subsum(Ysum,i,i,j+K-1,j+K-1) == midY * (subsum(sum,i,i+K-1,j,j+K-1)-subsum(sum,i,i,j,j) - subsum(sum,i+K-1,i+K-1,j+K-1,j+K-1) - subsum(sum,i+K-1,i+K-1,j,j) - subsum(sum,i,i,j+K-1,j+K-1)) )
			return true;
	}
	return false;
}
int main()
{
	int T=0,TT;
	int ans;
	for( scanf("%d",&TT);TT;TT-- )
	{
		printf("Case #%d: ",++T);
		scanf("%d%d%d",&n,&m,&D);
		char ch;
		for( int i = 1;i<=n;i++ )
		for( int j = 1;j<=m;j++ )
		{
			ch = getchar();
			while( ch < '0' || ch > '9' ) ch = getchar();

			a[i][j] = ch - '0';
		}

		for( int i = 1;i<=n;i++ )
		for( int j = 1;j<=m;j++ )
		{
			sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i][j];
			Xsum[i][j] = Xsum[i][j-1] + Xsum[i-1][j] - Xsum[i-1][j-1] + a[i][j] * (2*i-1);
			Ysum[i][j] = Ysum[i][j-1] + Ysum[i-1][j] - Ysum[i-1][j-1] + a[i][j] * (2*j-1);
		}

		ans = min(n,m);
		while( ans > 2 && !good(ans) ) ans --;
		if( ans > 2 ) printf("%d\n",ans);else
			puts("IMPOSSIBLE");
	}
	return 0;
}
