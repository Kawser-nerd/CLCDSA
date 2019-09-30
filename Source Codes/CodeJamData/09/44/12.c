#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int i,j,k,nc,ca,n;
	double R,ra;
	int x[3],y[3],r[3];
	scanf("%d ",&nc);
	for(ca=1;ca<=nc;ca++) {
		scanf("%d ",&n);
		for(i=0;i<n;i++)
			scanf("%d %d %d ",x+i,y+i,r+i);
		R=r[0];		
		if(n==1) {
			printf("Case #%d: %lf\n",ca,R);
			continue;
		}
		if(n==2) {
			if(r[1]>R)
				R=r[1];
			printf("Case #%d: %lf\n",ca,R);
			continue;
		}
		R=1000000;
		ra=sqrt(pow(x[0]-x[1],2)+pow(y[0]-y[1],2)) + r[0] + r[1];
		if(ra<R)
			R=ra;
		ra=sqrt(pow(x[0]-x[2],2)+pow(y[0]-y[2],2)) + r[0] + r[2];
		if(ra<R)
			R=ra;		
		ra=sqrt(pow(x[2]-x[1],2)+pow(y[2]-y[1],2)) + r[2] + r[1];
		if(ra<R)
			R=ra;		
		printf("Case #%d: %lf\n",ca,R/2);
	}
	return 0;
}
