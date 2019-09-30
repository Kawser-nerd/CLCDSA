
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include 	<regex.h>
#include 	<math.h>
int R1[200][200],R2[200][200];//1->opp,X->comb

	int
main ( int argc, char *argv[] )
{
	int i,tc,j,k;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++)
	{
		memset(R1,0,sizeof(R1));
		memset(R2,0,sizeof(R2));
		int x;char tmp[120];
		scanf("%d",&x);
		for(j=0;j<x;j++){
			scanf("%s",tmp);
			R1[tmp[0]+0][tmp[1]+0]=R1[0+tmp[1]][0+tmp[0]]=tmp[2];
		}
		scanf("%d",&x);
		for(j=0;j<x;j++){
			scanf("%s",tmp);
			R2[0+tmp[0]][0+tmp[1]]=R2[0+tmp[1]][0+tmp[0]]=1;
		}
		scanf("%d%s",&x,tmp);
		int S[200]={0},d;
		for(j=0;j<x;j++){
				if(S[0]&&(d=R1[S[S[0]]][0+tmp[j]])>1)
				{
					S[S[0]]=d;
				}
				else {
					for(k=S[0];k;k--)if(R2[S[k]][0+tmp[j]]==1)break;
					if(k>0)S[0]=0;
					else S[++S[0]]=tmp[j];
				}
		}
		printf("Case #%d: [",i);
		for(j=1;j<=S[0];j++)
		{printf("%c%s",S[j],j==S[0]?"":", ");}
		printf("]\n");

	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
