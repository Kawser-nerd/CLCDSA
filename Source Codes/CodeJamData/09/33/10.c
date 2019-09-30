#include<stdio.h>
#define infile "prisoners.in"
#define outfile "prisoners.out"
#define nmax (10*1001)
#define qmax 101
char v[nmax];
char viz[qmax];
int w[qmax];
int n,q;
int amin=~(1<<31);

void unset()
{
	amin=~(1<<31);
}

int aur(int p)
{
	int nr=0;
	int i;
	for(i=p-1;i>0 && !v[i];i--) nr++;
	for(i=p+1;i<=n && !v[i];i++) nr++;
	return nr;
}

void bk(int p, int a)
{
	int i,j;
	if(p==q)
	{
		amin=a;
	}
	else
		for(i=0;i<q;i++)
			if(!viz[i])
			{
				j=a+aur(w[i]);
				if(j<amin)
				{
					viz[i]=1;
					v[w[i]]=1;
					bk(p+1,j);
					v[w[i]]=0;
					viz[i]=0;
				}
			}
}

void solve()
{
	int i;
	for(i=0;i<q;i++)
	{
		viz[i]=1;
		v[w[i]]=1;
		bk(1,n-1);
		v[w[i]]=0;
		viz[i]=0;
	}
}

int main()
{
	int i,j,t;
	freopen(infile,"r",stdin);
	freopen(outfile,"w",stdout);
	
	scanf("%d\n",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d\n",&n,&q);
		for(j=0;j<q;j++) scanf("%d", &w[j]);
		solve();
		printf("Case #%d: %d\n",i,amin);
		unset();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}