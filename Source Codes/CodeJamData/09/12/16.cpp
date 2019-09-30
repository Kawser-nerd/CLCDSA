#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define infile "a2.in"
#define outfile "a2.out"

const int maxm = 21;
const int maxn = 21;
const int maxge = 1700;
const int maxnum = 2000000000;

struct Tlight{
	long s,w,t;
}light[maxm+1][maxn+1];

long m,n,ge,result;
long f[maxge+1],done[maxge+1];

FILE *fin=fopen(infile,"r"),
	*fout=fopen(outfile,"w");

void init()
{
	long i,j;
	fscanf(fin,"%ld%ld",&m,&n);	
	for (i=1; i<=m; ++i)
		for (j=1; j<=n; ++j)
			fscanf(fin,"%ld%ld%ld",&light[i][j].s,&light[i][j].w,&light[i][j].t);
}

inline long zhuan(long x,long y,long d)
{
	return ((x-1)*n+y-1)*4+d;
}

void zy(long v, long delta, long x,long y, long d)
{
	long q;
	if ((x>=1)&&(x<=m)&&(y>=1)&&(y<=n))
	{}
	else return;
	q=zhuan(x,y,d);
	if ((!done[q])&&(v+delta<f[q]))
		f[q]=v+delta;
}

void zycross(long v,long delta,long s,long w,long t,
			 long fx, long x,long y,long d)
{
	long wt,q;
	if (t<v)
		t+=(v-t)/(s+w)*(s+w);
	if (t>v)
		t-=(t-v)/(s+w)*(s+w);
	while (t>v)
		t-=(s+w);
	while (t+s+w<v)
		t+=(s+w);
	if (fx==0)
	{
		if (v<t+s)
			wt=0;
		else wt=t+s+w-v;
	}
	else {
		if ((v>=t+s)&&(v<t+s+w))
			wt=0;
		else if (v<t+s)
			wt=t+s-v;
		else wt=t+s+w+s-v;
	}
	q=zhuan(x,y,d);
	if ((!done[q])&&(v+delta+wt<f[q]))
		f[q]=v+delta+wt;
}

void work()
{
	long i,j,k,x,y,d,nx,ny,nd;
	ge=m*n*4;
	for (i=1; i<=ge; ++i)
	{
		f[i]=maxnum;
		done[i]=false;
	}
	f[zhuan(m,1,3)]=0;
	while (1)
	{
		j=-1;
		for (i=1; i<=ge; ++i)
			if ((f[i]!=maxnum)&&(!done[i]))
				if ((j==-1)||(f[i]<f[j]))
					j=i;
		if (j==-1)
			break;
		if (j==zhuan(1,n,2))
			break;
		done[j]=true;
		
		k=(j-1)/4+1;
		x=(k-1)/n+1;
		y=(k-1)%n+1;
		d=(j-1)%4+1;
	//	printf("%ld\n",j);
		if (d==1)
		{
			zy(f[j], 2, x-1, y , 3);
			zy(f[j], 2, x, y-1 , 2);
			zycross(f[j], 1, light[x][y].s, light[x][y].w, light[x][y].t, 0, x, y, 3);
			zycross(f[j], 1, light[x][y].s, light[x][y].w, light[x][y].t, 1, x, y, 2);
		}
		if (d==2)
		{
			zy(f[j], 2, x-1, y , 4);
			zy(f[j], 2, x, y+1 , 1);
			zycross(f[j], 1, light[x][y].s, light[x][y].w, light[x][y].t, 1, x, y, 1);
			zycross(f[j], 1, light[x][y].s, light[x][y].w, light[x][y].t, 0, x, y, 4);
		}
		if (d==3)
		{
			zy(f[j], 2, x, y-1 , 4);
			zy(f[j], 2, x+1, y , 1);
			zycross(f[j], 1, light[x][y].s, light[x][y].w, light[x][y].t, 1, x, y, 4);
			zycross(f[j], 1, light[x][y].s, light[x][y].w, light[x][y].t, 0, x, y, 1);
		}
		if (d==4)
		{
			zy(f[j], 2, x, y+1 , 3);
			zy(f[j], 2, x+1, y , 2);
			zycross(f[j], 1, light[x][y].s, light[x][y].w, light[x][y].t, 1, x, y, 3);
			zycross(f[j], 1, light[x][y].s, light[x][y].w, light[x][y].t, 0, x, y, 2);
		}
	}
	result = f[zhuan(1,n,2)];
}

void output()
{
	
}

int main()
{
	long w,t;
	fscanf(fin,"%ld",&t);
	for (w=1; w<=t; ++w)
	{	
		init();
		work();
		fprintf(fout,"Case #%ld: %ld\n",w,result);
		//output();	
	}
	fclose(fin);
	fclose(fout);
	return 0;
}