#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



void printCase(int i)
{
	printf("Case #%d: ",i+1);
}

int main()
{
	int cases,k;
	
	scanf("%d",&cases);
	for(k=0;k<cases;k++)
	{
		long int r,t;
		long int ans=0;
		
		scanf("%ld",&r);
		scanf("%ld",&t);
		while (t>0)
		{
			t=t-(2*r+1);
			r=r+2;
			ans++;
		}
		if(t<0) ans--;
		printCase(k);
		printf("%ld\n",ans);
	}
	return 0;
}
