#include<cstdio>
#include<algorithm>
using namespace std;

int f[100];
int l1,r1,l2,r2;

int lb( int a,int b )
{
	//bx >= a
	if( a<=0 ) return 0;else
		return (a-1)/b + 1;
}
long long calc( int l1,int r1,int l2,int r2 )
{
	int Bl;
	int Al,Au;
	int a1;
	int b1;
	long long ans = 0;
	
	for(int i=l2;i<=r2;i++) if( 2*i <= r1 )
		ans+= r1-max(l1,2*i) + 1;

	for(int t=2;t<=30;t+=2)
	{
		// A*f(t+2)+B*f(t+1)  , A*f(t+1)+B*f(t)
		Bl = min(r1/f[t+1],r2/f[t]);
		for(int j=1;j<=Bl;j++)
		{
			Au = min( (r1-j*f[t+1])/f[t+2],(r2-j*f[t])/f[t+1] );
			Al = max( max( lb(l1-j*f[t+1],f[t+2]),lb(l2-j*f[t],f[t+1]) ) , 2*j+(j==0) );
			if( Al<=Au ) ans+=Au-Al+1;
		}
	}
	return ans;
}
int main()
{
	f[0] = 1;
	f[1] = 0;
	for(int i=2;i<=32;i++) f[i]=f[i-1]+f[i-2];

	int T=0,Te;
	scanf("%d",&Te);
	while(Te--)
	{
		printf("Case #%d: ",++T);
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		printf("%I64d\n",calc(l1,r1,l2,r2)+calc(l2,r2,l1,r1));
	}
	return 0;
}
