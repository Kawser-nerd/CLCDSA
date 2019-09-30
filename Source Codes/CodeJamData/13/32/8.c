#include <stdio.h>
#include <stdlib.h>

#define require(X,Y) { if(!(X)) { fprintf(stderr,"%s\n",Y); exit(-1); } }
#define max(X,Y) ((X)>(Y)?(X):(Y))
#define min(X,Y) ((X)<(Y)?(X):(Y))

int main()
{
	int i,X,Y,T,tcase,k,x,y;
	char res[600],negX,negY;

	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%d %d",&X,&Y);
		negX = negY = 0;
		if(X<0)
		{
			X = -X;
			negX = 1;
		}
		if(Y<0)
		{
			Y = -Y;
			negY = 1;
		}
		x=y=0;
		i=0;
		while(x<X)
		{
			res[i]=negX?'W':'E';
			i++;
			x+=i;
		}
		while(y<Y)
		{
			res[i]=negY?'S':'N';
			i++;
			y+=i;
		}
		for(k=0;k<x-X;k++)
		{
			res[i++]=negX?'W':'E';
			res[i++]=negX?'E':'W';
		}
		for(k=0;k<y-Y;k++)
		{
			res[i++]=negY?'S':'N';
			res[i++]=negY?'N':'S';
		}
		res[i]=0;
		require(i<=500,"Too many steps!");

		printf("Case #%d: %s\n",tcase,res);
	}
	return 0;
}
