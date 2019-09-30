#include<stdio.h>
#define infile "bacteria.in"
#define outfile "bacteria.out"
#define nmax 313
struct harta
{
	char h[nmax][nmax]; //harta cu bacteriile
	int nr; //numarul de bacterii
} x[2]; //hartile
int count; //numarul de zile

int count_bacteria(struct harta x)
{
	int i,j,count=0;
	for(i=1;i<nmax;i++)
		for(j=1;j<nmax;j++)
			if(x.h[i][j])
				count++;
	return count;
}

void init()
{
	int i,j;

	x[0].nr=count=0;
	for(i=1;i<nmax;i++)
		for(j=1;j<nmax;j++)
			x[0].h[i][j]=0;
}

void read()
{
	int n;
	int i,j,x1,y1,x2,y2;
	scanf("%d\n",&n);
	while(n--)
	{
		scanf("%d %d %d %d\n",&x1,&y1,&x2,&y2);
		for(i=y1;i<=y2;i++)
			for(j=x1;j<=x2;j++)
				x[0].h[i][j]=1;
	}
	x[0].nr=count_bacteria(x[0]);
}

void solve()
{
	int i,j;

	while(x[count&1].nr)
	{
		count++;
		x[count&1].nr=0;
		for(i=1;i<nmax;i++)
			for(j=1;j<nmax;j++)
			{
				x[count&1].h[i][j]=x[(count-1)&1].h[i][j];
				if(!x[(count-1)&1].h[i-1][j] && !x[(count-1)&1].h[i][j-1]) x[count&1].h[i][j]=0;
				if(x[(count-1)&1].h[i-1][j] && x[(count-1)&1].h[i][j-1]) x[count&1].h[i][j]=1;
			}
		x[count&1].nr=count_bacteria(x[count&1]);
	}
}

int main()
{
	freopen(infile,"r",stdin);
	freopen(outfile,"w",stdout);
	int t,i;

	scanf("%d\n",&t);
	for(i=1;i<=t;i++)
	{
		init();
		read();
		solve();
		printf("Case #%d: %d\n",i,count);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
