#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define infile "c.in"

FILE *fin=fopen(infile,"r"),
	*fout=fopen("c.out","w");

struct Tresult
{
	int size, ge;
}result[600];

int m,n,resulttop;
int map[520][520],you[520][520],xia[520][520];


void calc_you_xia()
{
	int i,j;
	//calc you
	for (i=1; i<=m; ++i)
	{
		you[i][n]=1;
		for (j=n-1; j>=1; --j)
			if (map[i][j]!=map[i][j+1])
				you[i][j]=you[i][j+1]+1;
			else you[i][j]=1;
	}

	//calc xia
	for (j=1; j<=n; ++j)
	{
		xia[m][j]=1;
		for (i=m-1; i>=1; --i)
			if (map[i][j]!=map[i+1][j])
				xia[i][j]=xia[i+1][j]+1;
			else xia[i][j]=1;
	}
}

void work()
{
	int w,i,j,t,zd,x,y,area,current,k;
	calc_you_xia();
	resulttop=0;
	area=m*n;
	while (true)
	{
		if (area==0)
			break;
		zd=0;
		for (i=1; i<=m; ++i)
			for (j=1; j<=n; ++j)
				if (map[i][j]!=-1)
				{
					if ((xia[i][j]>zd)&&(you[i][j]>zd))
					{						
						current=you[i][j];
						if (xia[i][j]<current)
							current=xia[i][j];
						for (t=i; t<i+current; ++t)
						{
							if (map[t][j]==-1)
							{
								current=t-i;
								break;
							}
							if (you[t][j]<current)
							{
								if (you[t][j]>=t-i+1)
									current=you[t][j];
								else {
									current=t-i;
									break;
								}
							}
							if (current<=zd)
								break;
						}
						if (current>zd)
						{
							zd=current;
							x=i;
							y=j;
						}	
					}
				}



		if (zd>1)
		{
			for (i=x; i<x+zd; ++i)
				for (j=y; j<y+zd; ++j)
					map[i][j]=-1;
			//update you and xia
			for (i=x; i<x+zd; ++i)
			{
				j=y-1;
				t=1;
				while ((j>=1)&&(map[i][j]!=-1))
				{
					if (t<you[i][j])
						you[i][j]=t;
					if ((j<y-1)&&(map[i][j]==map[i][j+1])) //no effect from now
						break;
					++t;
					--j;
				}
			}
			for (j=y; j<y+zd; ++j)
			{
				i=x-1;
				t=1;
				while ((i>=1)&&(map[i][j]!=-1))
				{
					if (t<xia[i][j])
						xia[i][j]=t;
					if ((i<x-1)&&(map[i][j]==map[i+1][j])) //no effect from now
						break;
					++t;
					--i;
				}
			}

			area-=zd*zd;
			
			if ((resulttop==0)||(zd<result[resulttop].size))
			{
				result[++resulttop].size=zd;
				result[resulttop].ge=1;
			}
			else ++result[resulttop].ge;
		}
		else {
			result[++resulttop].size=1;
			result[resulttop].ge=area;
			break;
		}
	}
}

int main()
{
	int i,j,p,w,t,ge;
	char s[520];
	fscanf(fin,"%d",&ge);
	for (w=1; w<=ge; ++w)
	{
		fscanf(fin,"%d%d", &m, &n);
		for (i=1; i<=m; ++i)
		{
			fscanf(fin,"%s",s);
			p=0;
			for (j=0; j<n/4; ++j)
			{
				if ((s[j]>='0')&&(s[j]<='9'))
					t=s[j]-'0';
				else t=s[j]-'A'+10;
				if (t&8)
					map[i][++p]=1;
				else map[i][++p]=0;
				if (t&4)
					map[i][++p]=1;
				else map[i][++p]=0;
				if (t&2)
					map[i][++p]=1;
				else map[i][++p]=0;
				if (t&1)
					map[i][++p]=1;
				else map[i][++p]=0;
			}
		}

		resulttop=0;

		work();

		printf("Case #%d", w);
		fprintf(fout,"Case #%d: %d\n", w, resulttop);
		for (i=1; i<=resulttop; ++i)
			fprintf(fout,"%d %d\n", result[i].size, result[i].ge);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}