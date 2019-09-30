#include<cstdio>
#include<algorithm>
using namespace std;

const int INF = 1<<29;
int f[256],g[256];
int ans;
int I,D;
int n,m;

int Rec( int x )
{
	if(x==0) return 0;
	x=abs(x);
	if(m==0) return INF;
	if( x%m==0 ) return (x/m-1)*I;else return (x/m)*I;
}
int main()
{
	int Te,T=0;
	scanf("%d",&Te);
	while( Te-- )
	{
		printf("Case #%d: ",++T);
		scanf("%d%d%d%d",&D,&I,&m,&n);
		ans = D*n;
		for(int i=0;i<256;i++) f[i] = INF;
		int x;
		for(int t=1;t<=n;t++)
		{
			scanf("%d",&x);

			//I + change
			for(int i=0;i<256;i++)
			{
				g[i] = (t-1)*D + abs(x-i);
				for(int j=0;j<256;j++)
					g[i] = min(g[i],abs(x-i)+Rec(j-i)+f[j]);
			}
			
			for(int i=0;i<256;i++)
				f[i] = min(min(f[i]+D,g[i]),INF);
		}
		for(int i=0;i<256;i++) ans=min(ans,f[i]);
		printf("%d\n",ans);
	}
	return 0;
}
