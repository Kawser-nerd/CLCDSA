#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <cmath>
#include <string>
#define SIZE 105
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll dist[SIZE][SIZE];
double dp[SIZE][SIZE];
ll E[SIZE],S[SIZE];

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		int n,Q;
		scanf("%d %d",&n,&Q);
		for(int i=0;i<n;i++)
		{
			scanf("%lld %lld",&E[i],&S[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%lld",&dist[i][j]);
				if(i==j) dist[i][j]=0;
				else if(dist[i][j]==-1) dist[i][j]=INF;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j) dp[i][j]=0.0;
				else if(dist[i][j]<=E[i]) dp[i][j]=(double) dist[i][j]/(double) S[i];
				else dp[i][j]=(double) INF;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
				}
			}
		}
		for(int i=0;i<Q;i++)
		{
			if(i!=0) printf(" ");
			int s,t;
			scanf("%d %d",&s,&t);s--,t--;
			printf("%.10f",dp[s][t]);
		}puts("");
	}
	return 0;
}
