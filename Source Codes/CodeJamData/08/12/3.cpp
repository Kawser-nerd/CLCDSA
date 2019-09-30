#include <stdio.h>
#define infile "a2.in"
#define outfile "a2.out"

const long maxn = 2010;
const long maxm = 2010;

struct Tdf{
	long x,y;
}*df[maxm+1];

long deg[maxm+1],result[maxn+1],n,m;

FILE *fin=fopen(infile,"r"),
	*fout=fopen(outfile,"w");

void init()
{
	long i,j;
	fscanf(fin,"%ld%ld",&n,&m);	
	for (i=1; i<=m; i++)
	{
		fscanf(fin,"%ld",&deg[i]);
		df[i]=new Tdf[deg[i]+1];
		for (j=1; j<=deg[i]; j++)
			fscanf(fin,"%ld%ld",&df[i][j].x,&df[i][j].y);
	}
}

long check()
{
	long i,j;
	for (i=1; i<=m; i++)
	{	
		for (j=1; j<=deg[i]; j++)
			if (result[df[i][j].x]==df[i][j].y)
				break;
		if (j>deg[i])
			return i;
	}
	return i;
}

long work()
{
	long i,j,k;
	for (i=1; i<=n; i++)
		result[i]=0;
	while (1)
	{
		i=check();
		if (i>m)
			return 1;
		for (j=1; j<=deg[i]; j++)
			if (df[i][j].y==1)
				break;
		if (j>deg[i])
			return 0;
		result[df[i][j].x]=1;
	}
}

void output(long sign)
{
	long i;
	for (i=1; i<=m; i++)
		delete []df[i];
	if (!sign)
		fprintf(fout,"IMPOSSIBLE\n");
	else {
		for (i=1; i<=n; i++)
		{
			fprintf(fout,"%ld",result[i]);
			if (i==n)
				fprintf(fout,"\n");
			else fprintf(fout," ");
		}
	}
}

int main()
{
	long i,t;
	fscanf(fin,"%ld",&t);
	for (i=1; i<=t; i++)
	{
		init();
		fprintf(fout,"Case #%ld: ",i);
		output(work());
	}
	fclose(fin);
	fclose(fout);
	return 0;
}