#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define infile "a1.in"
#define outfile "a1.out"

const long maxnum = 20000000;

bool done[maxnum+1],yes[maxnum+1],
	df[11][maxnum+1],tot[maxnum+1];

FILE *fin=fopen(infile,"r"),
	*fout=fopen(outfile,"w");

void digui(long num,long base)
{
	long i,j,now=0;
	if ((base==10)&&(num==82))
				{
					num=num;
				}
	j=num;
	while (j!=0)
	{
		now+=(j%base)*(j%base);
		j/=base;
	}
	if (now==1)
	{
		yes[num]=1;
		return;
	}
	if (done[now])
	{
		yes[num]=yes[now];
		return;
	}
	done[now]=1;
	digui(now,base);
	yes[num]=yes[now];
}

void init()
{
	long i,j,k,w;	
	for (i=2; i<=10; ++i)
	{
		printf("i... %ld\n",i);
		for (j=1; j<=maxnum; ++j)
			done[j]=yes[j]=false;
		done[1]=yes[1]=1;
		for (j=2; j<=maxnum; ++j)
			if (!done[j])
			{				
				done[j]=true;
				digui(j,i);
			}
		for (j=1; j<=maxnum; ++j)
			df[i][j]=yes[j];
	}

	fscanf(fin,"%ld",&k);
	char s[1000];
	fgets(s,1000,fin);
	bool gao[11];
	int p;
	for (w=1; w<=k; ++w)
	{
		fgets(s,1000,fin);
		for (j=1; j<=maxnum; ++j)
			tot[j]=true;
		for (j=2; j<=10; ++j)
			gao[j]=false;
		p=0;
		while (p<strlen(s))
		{
			while ((p<strlen(s))&&((s[p]<'0')||(s[p]>'9')))
			{
				++p;
			}
			if (p>=strlen(s))
				break;
			i=0;
			while ((p<strlen(s))&&(s[p]>='0')&&(s[p]<='9'))
			{
				i=i*10+(s[p]-'0');
				++p;
			}
			gao[i]=true;			
		}
		bool success=false;
		for (j=2; j<=maxnum; ++j)
		{
			success=true;
			for (i=2; i<=10; ++i)
				if ((gao[i])&&(!df[i][j]))
				{
					success=false;
					break;
				}
			if (success)
				break;			
		}
		fprintf(fout,"Case #%ld: %ld\n",w,j);
	}
}

void work()
{


}

void output()
{
	fclose(fin);
	fclose(fout);
}

int main()
{
	init();
	work();
	output();	
	return 0;
}