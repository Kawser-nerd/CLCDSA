#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

int main(){
int i,j;
int T;
int N,A;
long double n[2][2000],a[250],D;


	scanf("%d", &T);		// cant casos
	for(i=0;i<T;i++){
		scanf("%Lf %d %d",&D,&N,&A);	

		for(j=0;j<N;j++) 
			scanf("%Lf %Lf",&n[0][j],&n[1][j]);

		for(j=0;j<A;j++) 
			scanf("%Lf",&a[j]);

		printf("Case #%d:\n", i+1);
		for(j=0;j<A;j++)
			if(N == 1)
				printf("%.7Lf\n",sqrtl(2*D/a[j]));
			else
				printf("%.7Lf\n",max((D-n[1][0])*((n[0][1]-n[0][0])/(n[1][1]-n[1][0])),sqrt(2*D/a[j])));
	}

	return 0;
}
