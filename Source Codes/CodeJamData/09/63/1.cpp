#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

const int MOD = 10007;
const int maxnode = 400000;

int child[maxnode][11];
int value[maxnode];
int tot;

int *tmin,*tmax;
int minh[26][10],maxh[26][10];
char s[100];
int n,m;
int seq[100],seq2[100];

void dfs( int tp,int dep,int last )
{
	if( dep>m ) return;

	for(;last>=0;last--)
	{
		if( child[tp][last]==0 )
		{
			tot++;
			value[tot] = 0;
			for(int i=0;i<=n;i++) child[tot][i] = 0;

			child[tp][last] = tot;
		}
		dfs( child[tp][last],dep+1,last );
	}
}
void build()
{
	tot = 0;
	for(int i=0;i<=n;i++) child[0][i] = 0;
	value[0] = 0;

	dfs( 0,1,n );
}
bool flag;
int tmp;
void calc( int tp,int dep,int last,int &res,int ct )
{
	if( dep==m )
	{
		if( ct&1 )
		{
			res = res + value[tp];if(res>=MOD) res-=MOD;
		}else
		{
			res = res - value[tp];if(res<0) res+=MOD;
		}
	}else
	for( int i=0;i<2;i++ ) if( seq[dep]+i<=last && ( i==0 || dep==0 || seq[dep]!=seq[dep-1] ) )
		calc( child[tp][ seq[dep]+i ],dep+1,seq[dep]+i,res,ct+i );
}
void work( int tp,int dep,int last )
{
	if( dep==m )
	{
//		for(int i=0;i<m;i++) printf("%d,",seq[i]);
//		printf("    %d\n",value[tp]);

		flag = false;
		for(int i=0;i<m;i++) if( seq[i] < tmax[i] )
		{
			seq2[i] = tmax[i];flag = true;
		}else seq2[i] = seq[i];

		if(flag)
		{
			for(int i=m-2;i>=0;i--) if( seq2[i+1] > seq2[i] ) seq2[i] = seq2[i+1];
			int k = 0;
			for(int i=0;i<m;i++) k = child[k][ seq2[i] ];
			value[tp] = value[k];
		}else
		{
			tmp = 2*value[tp]%MOD;
			calc( 0,0,n,tmp,0 );
			value[tp] = tmp;
		}
	}else
	for(;last>=0;last--) work(child[tp][seq[dep]=last],dep+1,last);
}
void kick( int tp,int dep,int last )
{
	if( dep==m )
	{
//		for(int i=0;i<m;i++) printf("%d,",seq[i]);
//		printf("    %d\n",value[tp]);
		for(int i=0;i<m;i++) if( seq[i] >= tmin[i] )
		{
			value[tp] = 0;
			return;
		}
	}else
	for(;last>=0;last--) kick(child[tp][seq[dep]=last],dep+1,last);
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int num=1;num<=T;num++)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<26;i++)
		for(int j=0;j<m;j++)
		{
			minh[i][j] = n+1;
			maxh[i][j] = 0;
		}

		gets(s);
		for(int i=1;i<=n;i++)
		{
			gets(s);
			for(int j=0;j<m;j++) if(s[j]!='.')
			{
				if( minh[ s[j]-'a' ][ j ]==n+1) minh[ s[j]-'a' ][ j ] = i;
				maxh[ s[j]-'a' ][ j ] = i;
			}
		}

		build();

		value[m] = 1;
		for( int p = 'z';p>='a';p-- )
		{
	//		printf("Calcing %c:\n",p);
			tmin = minh[p-'a'];
			tmax = maxh[p-'a'];
	//		for(int i=0;i<m;i++) printf("%d ",tmin[i]);puts("");
	//		for(int i=0;i<m;i++) printf("%d ",tmax[i]);puts("");
			work( 0,0,n );
	//		printf("Before Kick\n");
			kick( 0,0,n );
		}

		int k = 0;
		for(int i=1;i<=m;i++) k=child[k][0];
		printf("Case #%d: %d\n",num,value[k]);
	}
	return 0;
}
