#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 10;

int X,S,R,rt,n;

int L[maxn],w[maxn];
int last;

double leftT;
double ans;

void deal( double T,int S,int R )
{
	double rt = min( leftT,T/R );

	ans += rt;
	T -= rt * R;
	leftT -= rt;

	ans += T / S;
	//”√S
}
int main()
{
	int TT,T=0;
	for( scanf("%d",&TT);TT;TT-- )
	{
		printf("Case #%d: ",++T);
		scanf("%d%d%d%d%d",&X,&S,&R,&rt,&n);
		L[0]=X;w[0] = 0;
		for( int i = 1;i<=n;i++ )
		{
			int B,E;
			scanf("%d%d%d",&B,&E,w+i);
			L[i] = E - B;
			L[0] -= L[i];
		}
		for( int i = 0;i<=n;i++ )
		for( int j = i+1;j<=n;j++ ) if( w[i] > w[j] )
		{
			swap( w[i],w[j] );
			swap( L[i],L[j] );
		}

		leftT = rt;
		last = 0;
		ans = 0;
		for( int i = 0;i<=n;i++ ) deal( L[i],S+w[i],R+w[i] );

		printf("%.15lf\n",ans);
	}
	return 0;
}
