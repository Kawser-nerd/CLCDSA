
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include 	<regex.h>
#include 	<math.h>
int l,d,tc;
char t[5100][20],tmp[1000];
regex_t reg;
regmatch_t pm[1];
#define LN 101
#define RN 101
int vis[RN],match[RN];
int wt[LN][RN];
int m,n;
int sp(int a)
{
	int i;
	for(i=1;i<=wt[a][0];i++)
	{
		if(!vis[wt[a][i]])
		{
			vis[wt[a][i]]=1;
			if(match[wt[a][i]]==0||sp(match[wt[a][i]]))
			{
				match[wt[a][i]]=a;
				return 1;
			}
		}
	}
	return 0;

}
void zdpp()
{
	int i,sum=0;
	for(i=1;i<=m;i++){memset(vis,0,sizeof(vis));sum+=sp(i);}
	for(i=1;i<=n;i++){printf("%d-%d",i,match[i]);}
}
	int
main ( int argc, char *argv[] )
{
	int i,j;
	scanf("%d%d%d",&l,&d,&tc);
	for(i=1;i<=d;i++)scanf("%s",t[i]);
	for(i=1;i<=tc;i++)
	{
		//printf("Case %d:",i+1);
		scanf("%s",tmp);
		char *p=tmp;
		while(*p){
			if(*p=='(')*p='[';
			if(*p==')')*p=']';
			p++;
		}
		regcomp(&reg,tmp,0);
		for(j=1;j<=d;j++)if(regexec(&reg,t[j],1,pm,0)!=REG_NOMATCH)wt[j][++wt[j][0]]=i;

	}
	m=d;n=tc;
	zdpp();
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
