#include<stdio.h>
#define infile "rope.in"
#define outfile "rope.out"
#define nmax 1013
struct dreapta
{
	int st, dr;
} v[nmax]; //dreptele
int n; //numarul de drepte
int nr; //numarul de intersectii

int intersect(struct dreapta a, struct dreapta b)
{
	if(a.st>b.st && a.dr<b.dr) return 1;
	if(a.st<b.st && a.dr>b.dr) return 1;
	return 0;
}

void init()
{
	nr=0;
}

void read()
{
	int i;
	scanf("%d\n",&n);
	for(i=1;i<=n;i++)
		scanf("%d %d\n",&v[i].st,&v[i].dr);
}

void solve()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(intersect(v[i],v[j]))
				nr++;
}

int main()
{
	freopen(infile,"r",stdin);
	freopen(outfile,"w",stdout);
	int i,t;

	scanf("%d\n",&t);
	for(i=1;i<=t;i++)
	{
		init();
		read();
		solve();
		printf("Case #%d: %d\n",i,nr);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

