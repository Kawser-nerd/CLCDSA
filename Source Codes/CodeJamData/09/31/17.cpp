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

FILE *fin=fopen("A-large.in","r");
FILE *fout=fopen("A-large.out","w");

#define MAXN 1001

int n;
char p[MAXN];
int c[100];
int f[100];

int num(char x)
{
	if (x>='0'&&x<='9')
		return x-'0';
	return x-'a'+10;
}

void search()
{
	int i;
	int b=0,cnt=0;
	int64 ret,base;

	fscanf(fin,"%s",p);
	n=strlen(p);
	for (i=0; i<100; i++)
	{
		c[i]=0;
		f[i]=-1;
	}
	for (i=0; i<n; i++)
	{
		c[num(p[i])]=1;
	}
	for (i=0; i<100; i++)
		b+=c[i];
	if (b==1)
		b=2;
	f[num(p[0])]=1;
	for (i=1; i<n; i++)
	{
		if (f[num(p[i])]==-1)
		{
			f[num(p[i])]=cnt;
			cnt++;
			if (cnt==1)
				cnt++;
		}
	}

	base=1;
	ret=0;
	for (i=n-1; i>=0; i--)
	{
		ret+=base*f[num(p[i])];
		base*=b;
	}
	fprintf(fout,"%I64d\n",ret);
}

int main()
{
	int testdata,i;

	fscanf(fin,"%d",&testdata);
	for (i=0; i<testdata; i++)
	{
		fprintf(fout,"Case #%d: ",i+1);
		search();
	}
	return 0;
}
