#include<cstdio>
#define MAXN 1006
#include<cstring>
#include<algorithm>
#define MOD 1000000007
using namespace std;
long long k,ud,lr,v,eh,ev;
int n,m;
char G[MAXN][MAXN];
long long ksm(long long a,long long b)
{
	if(!b) return 1;
	long long nex=ksm(a,b/2);
	nex=(nex*nex)%MOD;
	if(b%2==1) nex=(nex*a)%MOD;
	return nex;
}
struct node
{
	long long a[4][4];
}a,b;
node operator *(node a,node b)
{
	node re;
	memset(re.a,0,sizeof re.a);
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			for(int k=1;k<=2;k++)
			{
				re.a[i][j]+=(a.a[i][k]%MOD)*(b.a[k][j]%MOD);
				re.a[i][j]%=MOD;
			}
	return re;
}
node matksm(node a,long long k)
{
	if(k==1) return a;
	node nex=matksm(a,k/2);
	nex=nex*nex;
	if(k%2==1) nex=nex*a;
	return nex;
}
int main()
{
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%s",G[i]+1);
	if(k==1||k==0)
	{
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(G[i][j]=='#')
			{
				v++;
				if(G[i][j+1]=='#') eh++;
				if(G[i-1][j]=='#') ev++;
				if(i==1)
				{
					if(G[n][j]=='#') ud++;
				}
				if(j==1)
				{
					if(G[i][m]=='#') lr++;
				}
			}
		}
	if(lr>0&&ud>0)
	{
		printf("1");
		return 0;
	}
	if(lr==0&&ud==0)
	{
		printf("%lld",ksm(v,k-1));
		return 0;
	}
	if(lr>0)
	{
		swap(lr,ud);
		swap(ev,eh);
	}
	a.a[1][1]=ud;
	a.a[2][1]=ev;
	a.a[1][2]=0;
	a.a[2][2]=v;
	b.a[1][1]=0;
	b.a[1][2]=1;
	b=b*matksm(a,k-1);
	printf("%lld",((b.a[1][2]-b.a[1][1])%MOD+MOD)%MOD);
}