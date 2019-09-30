#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX(a,b) ((a)<(b)?(b):(a))
#define INF INF32
#define NA (-1)

#define uint64 unsigned __int64
#define _1 ((uint64)1)
#define int64 __int64

const int64 INF64=(_1<<63)-1;
const int INF32=(_1<<31)-1;

using namespace std;

FILE *fin=fopen("C-large.in","r");
FILE *fout=fopen("C-large.out","w");

#define MAXN 201

int n,m;
int q[MAXN];
int p[MAXN];
int f[MAXN][MAXN];

void init()
{
	int i,j;

	fscanf(fin,"%d %d",&n,&m);
	for (i=0; i<m; i++)
		fscanf(fin,"%d",&q[i]);
	p[0]=q[0]-1;
	for (i=1; i<m; i++)
		p[i]=q[i]-q[i-1]-1;
	p[m]=n-q[m-1];
	for (i=0; i<MAXN; i++)
		for (j=0; j<MAXN; j++)
			f[i][j]=-1;
}

int dg(int s,int t)
{
	int i,j,c1,c2,temp;

	if (f[s][t]!=-1)
		return f[s][t];

	if (s==t)
		return 0;

	for (i=s; i<t; i++)
	{
		c1=0;
		for (j=s; j<=i; j++)
			c1+=p[j];
		c1+=(i-s);

		c2=0;
		for (j=i+1; j<=t; j++)
			c2+=p[j];
		c2+=(t-i-1);

		temp=c1+c2+dg(s,i)+dg(i+1,t);
		if (f[s][t]==-1)
			f[s][t]=temp;
		else
			f[s][t]=min(f[s][t],temp);
	}
	return f[s][t];
}

void search()
{
	fprintf(fout,"%d\n",dg(0,m));
}

int main()
{
	int testdata,i;

	fscanf(fin,"%d",&testdata);
	for (i=0; i<testdata; i++)
	{
		fprintf(fout,"Case #%d: ",i+1);
		init();
		search();
	}
	return 0;
}
