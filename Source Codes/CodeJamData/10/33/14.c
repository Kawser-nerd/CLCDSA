#include<stdio.h>
#define infile "making.in"
#define outfile "making.out"
#define nmax 535
char sir[nmax]; //sirul unde citim liniile
char h[nmax][nmax]; //harta
int dp[nmax][nmax]; //dp[i][j]=cea mai mare tabla ce incepe din acest punct
int down[nmax][nmax]; //down[i][j]=cel mai lung sir alternant in jos fata de acest punct
int right[nmax][nmax]; //right[i][j]=cel mai lung sir alternant in dreapta fata de acest punct
int count[nmax]; //count[i]=cate table avem de dimensiunea i
int n; //numarul de linii
int m; //numarul de coloane
int nr; //numarul de dimensiuni distincte

inline int min(int a, int b)
{
	if(a<b) return a; return b;
}

inline int max(int a, int b)
{
	if(a>b) return a; return b;
}

int maxim()
{
	int i,j,lg=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			lg=max(lg,dp[i][j]);
	return lg;
}

void erase(int x, int y, int lg)
{
	int i,j;
	for(i=0;i<lg;i++)
		for(j=0;j<lg;j++)
			h[x+i][y+j]=-1;
}

int verif(int x, int y, int lg)
{
	int i,j;
	for(i=0;i<lg;i++)
		for(j=0;j<lg;j++)
			if(h[x+i][y+j]==-1)
				return 0;
	return 1;
}

void read()
{
	int i,j;
	scanf("%d %d\n",&n,&m);
	for(i=1;i<=n;i++)
	{
		fgets(sir+1,nmax,stdin);
		for(j=1;j<=(m>>2);j++)
		{
			if(sir[j]>='0' && sir[j]<='9') sir[j]-='0';
			else sir[j]=10+(sir[j]-'A');
			h[i][((j-1)<<2)+1]=(sir[j]>>3)&1;
			h[i][((j-1)<<2)+2]=(sir[j]>>2)&1;
			h[i][((j-1)<<2)+3]=(sir[j]>>1)&1;
			h[i][((j-1)<<2)+4]=(sir[j]>>0)&1;
		}
	}
}

void init()
{
	int i;

	for(i=0;i<nmax;i++) count[i]=0;
	nr=0;
}

void dinamica()
{
	int i,j;

	//facem dinamica
	for(i=n;i>0;i--)
		for(j=m;j>0;j--)
			if(h[i][j]==-1) dp[i][j]=down[i][j]=right[i][j]=0;
			else
			{
				//down
				if(i==n) down[i][j]=1;
				else if(h[i][j]!=h[i+1][j]) down[i][j]=down[i+1][j]+1;
				else down[i][j]=1;

				//right
				if(j==m) right[i][j]=1;
				else if(h[i][j]!=h[i][j+1]) right[i][j]=right[i][j+1]+1;
				else right[i][j]=1;

				//dinamica
				if(i==n || j==m) dp[i][j]=1;
				else if(h[i][j]!=h[i+1][j+1]) dp[i][j]=1;
				else dp[i][j]=min(dp[i+1][j+1]+1,min(down[i][j],right[i][j]));
			}
}

void solve()
{
	int i,j,lg;
	do
	{
		dinamica();
		lg=maxim();
		if(!lg) break;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(h[i][j]!=-1 && dp[i][j]==lg && verif(i,j,lg))
					erase(i,j,lg), count[lg]++;
	}
	while(1);
	for(i=1;i<nmax;i++)
		if(count[i])
			nr++;
}

void write(int test)
{
	int i;
	printf("Case #%d: %d\n",test,nr);
	for(i=nmax-1;i>0;i--)
		if(count[i])
			printf("%d %d\n",i,count[i]);
}

int main()
{
	freopen(infile,"r",stdin);
	freopen(outfile,"w",stdout);
	int i,t;

	scanf("%d\n",&t);
	for(i=1;i<=t;i++)
	{
		read();
		init();
		solve();
		write(i);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
