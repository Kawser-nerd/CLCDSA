#include<stdio.h>
typedef unsigned u;
char M[55][55];
int main()
{
	u T,t=0,q,r,x,y,i,j,I,J,k;
	for(scanf("%u",&T);t++<T;)
	{
		scanf("%u%u%u",&x,&y,&q);
		printf("Case #%u:\n",t);
		for(i=0;i<x;i++)for(j=0;j<y;j++)M[i][j]='*';
		M[0][0]='c';
		q=x*y-q;
		if(q==1)goto fin;
		if(x==1)
		{
			for(j=0;--q;M[0][++j]='.');
			goto fin;
		}
		if(y==1)
		{
			for(i=0;--q;M[++i][0]='.');
			goto fin;
		}
		if(q==2||q==3||q==5||q==7){no:;printf("Impossible\n");continue;}
		if(x==2)
		{
			if(q&1)goto no;
			M[1][0]='.';
			for(j=1;q-=2;j++)M[0][j]=M[1][j]='.';
			goto fin;
		}
		if(y==2)
		{
			if(q&1)goto no;
			M[0][1]='.';
			for(i=1;q-=2;i++)M[i][0]=M[i][1]='.';
			goto fin;
		}
		if(q<3*y)
		{
			k=q/3;
			i=0;j=1;goto duh;
			for(;i<3;i++)for(j=0;j<k;j++){duh:;M[i][j]='.';}
			if(q%3==1){M[2][k-1]='*';q=2;}
			else q%=3;
			for(i=0;i<q;i++)M[i][k]='.';
		}
		else
		{
			k=q/y;
			i=0;j=1;goto loop;
			for(;i<k;i++)for(j=0;j<y;j++){loop:;M[i][j]='.';}
			if(q%y==1){M[k-1][y-1]='*';q=2;}
			else q%=y;
			for(j=0;j<q;j++)M[k][j]='.';
		}
		fin:;
		for(i=0;i<x;i++)
		{
			for(j=0;j<y;j++)putchar(M[i][j]);
			putchar('\n');
		}
	}
	return 0;
}
