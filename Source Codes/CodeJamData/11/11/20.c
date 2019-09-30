
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include 	<regex.h>
#include 	<math.h>
long long gcd(long long a,long long b)
{return b?gcd(b,a%b):a;}
	int
main ( int argc, char *argv[] )
{
	int i,tc;long long n;int d,g;
	scanf("%d",&tc);
	for(i=0;i<tc;i++)
	{
		scanf("%lld%d%d",&n,&d,&g);
		printf("Case #%d: ",i+1);
		if(n>=100/gcd(d,100)&&(
		   (d==100&&g==100)||
		   (d==0&&g==0)||
		   (g<100&&g>0)
		   ))
			printf("Possible\n");
		else printf("Broken\n");

	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
