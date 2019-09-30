
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include 	<regex.h>
#include 	<math.h>
char bd[111][111];
int n,tt[111];
double op[111],oop[111],ooop[111];
	int
main ( int argc, char *argv[] )
{
	int i,tc,j,k;
	scanf("%d",&tc);
	for(k=0;k<tc;k++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",bd[i]);
		int wn;
		for(i=0;i<n;i++)
		{
			tt[i]=wn=0;
			for(j=0;j<n;j++)
			{
				if(bd[i][j]=='1')wn++;
				if(bd[i][j]!='.')tt[i]++;
			}
			op[i]=(double)wn/tt[i];
		}
		double sc;
		for(i=0;i<n;i++)
		{
			sc=0.0;
			for(j=0;j<n;j++)
			{
				if(bd[i][j]!='.'){
					sc+=(op[j]*tt[j]-(bd[i][j]=='0'?1:0))/(tt[j]-1);}
			}
			oop[i]=sc/tt[i];
		}
		for(i=0;i<n;i++)
		{
			sc=0.0;
			for(j=0;j<n;j++)
			{
				if(bd[i][j]!='.'){sc+=oop[j];}
			}
			ooop[i]=sc/tt[i];
		}

		printf("Case #%d:\n",k+1);
		for(i=0;i<n;i++)printf("%.9f\n",0.25*op[i]+0.5*oop[i]+0.25*ooop[i]);

	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
