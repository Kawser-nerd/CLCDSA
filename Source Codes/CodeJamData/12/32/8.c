#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define require(X,Y) { if(!(X)) { fprintf(stderr,"%s\n",Y); exit(-1); } }
#define max(X,Y) ((X)>(Y)?(X):(Y))

int main()
{
	int i,tcase,T,N,A;
	double D,t[2000],x[2000],a[250],mine,other,res,v;
	
	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%lf",&D);
		scanf("%d %d",&N,&A);
		require(N<=2,"N>2");
		for(i=0;i<N;i++)
			scanf("%lf %lf",t+i,x+i);
		for(i=0;i<A;i++)
			scanf("%lf",a+i);

		if(x[0]>=D)
			other=0;
		else
		{
			v=(x[1]-x[0])/t[1];
			other=(D-x[0])/v;
		}

		printf("Case #%d:\n",tcase);
		for(i=0;i<A;i++)
		{
			mine=sqrt(2*D/a[i]);
			res=max(other,mine);
			printf("%.7f\n",res);
		}
	}


	return 0;
}
