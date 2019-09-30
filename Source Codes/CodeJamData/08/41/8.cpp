#include <vector>
#include <algorithm>
using namespace std;
#include <stdio.h>
#include <string.h>

FILE *Fin = fopen("A-large.in","r");
FILE *Fou = fopen("a.out","w");
//FILE *Fin = stdin;
//FILE *Fou = stdout;

#define MaxN 20000

int n,m;
int type[MaxN], change[MaxN];
int opt[MaxN][2];

inline int Min(int a, int b) { return a>b ? b : a; }

inline void set(int &a, int b) { a = Min(a,b); }

void make(int u)
{
	if (u>(n-1)/2)
	{
		opt[u][type[u]] = 0;
		opt[u][1-type[u]] = 1000000;
		return;
	}
	make(u+u); make(u+u+1);
	if (u==4)
		u = 4;
	int extra;
	opt[u][0] = opt[u][1] = 1000000;
	if (type[u]==1)
	{
		// And
		extra = 0;
		set(opt[u][0], extra + Min(opt[u*2][0] + Min(opt[u*2+1][0], opt[u*2+1][1]), Min(opt[u*2][0], opt[u*2][1]) + opt[u*2+1][0]));
		set(opt[u][1], extra + opt[u*2][1] + opt[u*2+1][1]);
		if (change[u]==1)
		{
			extra = 1;
			set(opt[u][1], extra + Min(opt[u*2][1] + Min(opt[u*2+1][0], opt[u*2+1][1]), Min(opt[u*2][0], opt[u*2][1]) + opt[u*2+1][1]));
			set(opt[u][0], extra + opt[u*2][0] + opt[u*2+1][0]);
		}
	}
	else
	{
		// Or
		if (change[u]==1)
		{
			extra = 1;
			set(opt[u][0], extra + Min(opt[u*2][0] + Min(opt[u*2+1][0], opt[u*2+1][1]), Min(opt[u*2][0], opt[u*2][1]) + opt[u*2+1][0]));
			set(opt[u][1], extra + opt[u*2][1] + opt[u*2+1][1]);
		}
		extra = 0;
		set(opt[u][1], extra + Min(opt[u*2][1] + Min(opt[u*2+1][0], opt[u*2+1][1]), Min(opt[u*2][0], opt[u*2][1]) + opt[u*2+1][1]));
		set(opt[u][0], extra + opt[u*2][0] + opt[u*2+1][0]);
	}
}

int main()
{
	int i,j,k,caseN;
	fscanf(Fin,"%d",&caseN);
	for (int t=1; t<=caseN; t++)
	{
		fscanf(Fin,"%d%d",&n,&m);
		for (i=1; i<=(n-1)/2; i++)
			fscanf(Fin,"%d%d",type+i, change+i);
		for (i=(n-1)/2+1; i<=n; i++)
			fscanf(Fin,"%d", type+i);

		make(1);
		fprintf(Fou,"Case #%d: ",t);
		if (opt[1][m]>=1000000)
			fprintf(Fou,"IMPOSSIBLE\n");
		else
			fprintf(Fou,"%d\n",opt[1][m]);


	}
	return 0;
}

