#include<stdio.h>
#include<algorithm>
#include<string.h>

char rr[50][64];
int main()
{
	int t;
	scanf("%d", &t);
	for(int cc=1;cc<=t;cc++)
	{
		int r, c;
		scanf("%d%d", &r, &c);
		for(int i=0;i<r;i++)
		{
			scanf("%s", rr[i]);
		}
		bool s=true;
		for(int i=0;s&&i<r-1;i++)
		{
			for(int j=0;s&&j<c-1;j++)
			{
				if(rr[i][j]=='#')
				{
					if(rr[i][j]=='#') rr[i][j]='/';
					else s=false;
					if(rr[i][j+1]=='#') rr[i][j+1]='\\';
					else s=false;
					if(rr[i+1][j]=='#') rr[i+1][j]='\\';
					else s=false;
					if(rr[i+1][j+1]=='#') rr[i+1][j+1]='/';
					else s=false;
				}
			}
		}
		for(int i=0;s&&i<r;i++)
		{
			for(int j=0;s&&j<c;j++)
			{
				if(rr[i][j]=='#')
				{
					s=false;
				}
			}
		}
		if(s)
		{
			printf("Case #%d:\n", cc);
			for(int i=0;i<r;i++) puts(rr[i]);
		}
		else
		{
			puts("Impossible");
		}
	}
}
