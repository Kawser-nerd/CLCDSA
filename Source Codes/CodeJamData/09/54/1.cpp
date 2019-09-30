#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

const int MOD = 1000000007;

LL e[20];
LL L,R;
LL a[50000000];
int tot;
void dfs( int l,int r,LL x )
{
	if( x>R ) return;
	if( l>r )
	{
		if( x>=L ) a[++tot] = x;
	}else
	{
		for(int t=0;t<10;t++)
		{
			if( l>0 || t>0 ) dfs(l+1,r-1,x);
			x+=e[l];if(l!=r) x+=e[r];
		}
	}
}

LL res[2];
LL ans,d,d2;
int main()
{
	e[0] = 1;
	for(int i=1;i<20;i++) e[i] = e[i-1]*10;
	int T;
	cin>>T;
	for( int num=1;num<=T;num++ )
	{
		cin>>L>>R;
		tot = 0;
		for(int len = 1;len<=13;len++) dfs(0,len-1,0);
		a[0] = L-1;
		a[tot+1] = R+1;
		res[0] = res[1] = 0;

		ans = 0;
		for(int i=1;i<=tot+1;i++)
		{
			d = (a[i] - a[i-1] -1)%MOD;
			ans = (ans + d*(d+1)/2)%MOD;
			//II1
		}
		for(int i=1;i<=tot+1;i++)
		{
			d = a[i]-a[i-1] -1;

			ans = ( ans +  (d%MOD)*((i-1)/2) ) %MOD;// PI
			if( i<=tot ) ans = ( ans + res[(i+1)&1] )%MOD;	//IP
			ans = ( ans + (d%MOD)*res[i&1] ) % MOD;//II2
			if(i<=tot) ans = ( ans + i/2 )%MOD;//PP
			res[i&1]=(res[i&1]+d)%MOD;
		}


		cout<<"Case #"<<num<<": "<<ans<<endl;
	}
	return 0;
}
