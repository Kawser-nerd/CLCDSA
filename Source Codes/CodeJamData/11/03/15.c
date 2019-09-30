
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include 	<regex.h>
#include 	<math.h>
int a;
	int
main ( int argc, char *argv[] )
{
	int i,tc,j;
	scanf("%d",&tc);
	for(i=0;i<tc;i++)
	{
		int n,t=0,sum=0,min=1000000;
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d",&a);
			t^=a;
			sum+=a;
			if(a<min)min=a;
		}
		printf("Case #%d: ",i+1);
		if(t)printf("NO\n");
		else{
			printf("%d\n",sum-min);
		}

	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
