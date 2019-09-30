#include<stdio.h>
#define infile "wcup.in"
#define outfile "wcup.out"
#define pmax 11
#define nmax (1<<pmax)
long long dp[pmax][nmax][pmax]; //dinamica
int co[pmax][nmax]; //costurile meciurilor
int m[nmax]; //numarul de meciuri ce trebuie sa le vad pt fiecare echipa
int p; //numarul de runde
int n; //numarul de echipe

inline long long min(long long a, long long b)
{
	if(a<b) return a; return b;
}

void read()
{
	int i,j;
	scanf("%d\n",&p);
	n=(1<<p);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		m[i]=p-j;
	}
	for(i=1;i<=p;i++)
		for(j=1;j<=(1<<(p-i));j++)
			scanf("%d",&co[i][j]);
}

void init()
{
	int i,j,k;
	for(i=0;i<=p;i++)
		for(j=1;j<=n;j++)
			for(k=0;k<=n;k++)
				dp[i][j][k]=((long long)1<<55);

	for(i=1;i<=n;i++)
		dp[0][i][m[i]]=0;
}

void solve()
{
	int i,j,k,l;
	int st,dr;
	long long cost,codr;

	for(i=1;i<=p;i++)
		for(j=1;j<=(1<<(p-i));j++)
			for(k=0;k<=p-i;k++)
			{
				//incercam mai intai fara sa vedem acest meci
				st=(j<<1), dr=st-1;
				cost=codr=((long long)1<<55);
				for(l=0;l<=k;l++)
				{
					cost=min(cost,dp[i-1][st][l]);
					codr=min(codr,dp[i-1][dr][l]);
				}
				dp[i][j][k]=cost+codr;
				//acum vedem daca vazand meciul scoatem mai ieftin
				cost=min(cost,dp[i-1][st][k+1]);
				codr=min(codr,dp[i-1][dr][k+1]);
				dp[i][j][k]=min(dp[i][j][k], co[i][j]+cost+codr);
			}
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
		printf("Case #%d: %lld\n",i,dp[p][1][0]);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
