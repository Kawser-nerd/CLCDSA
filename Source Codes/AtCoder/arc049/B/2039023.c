#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>

long n;
float rt;
long *x;
long *y;
long *spd;

int cmp(const void *a,const void *b){
    return (*(long *)a>*(long *)b)?1:((*(long *)a<*(long *)b)?-1:0);
}

int main(){
    //printf("%d\n",INT_MAX);
	scanf("%ld",&n);
    x=(long*)valloc(sizeof(long)*n);
	y=(long*)valloc(sizeof(long)*n);
	spd=(long*)valloc(sizeof(long)*n);
	long i;
	for(i=0;i<n;i++){
		scanf("%ld %ld %ld",&(x[i]),&(y[i]),&(spd[i]));
	}
	
	float tmax[2],dx,pt;
	long m,j;
	
	for(i=0;i<n-1;i++){
		for(j=i;j<n;j++){
			dx=(x[i]-x[j])>=0?(x[i]-x[j]):(x[j]-x[i]);
			pt=dx/(1.0/spd[i]+1.0/spd[j]);
			tmax[0]=(tmax[0]>pt)?tmax[0]:pt;
		}
	}
	for(i=0;i<n-1;i++){
		for(j=i;j<n;j++){
			dx=(y[i]-y[j])>=0?(y[i]-y[j]):(y[j]-y[i]);
			pt=dx/(1.0/spd[i]+1.0/spd[j]);
			tmax[1]=(tmax[1]>pt)?tmax[1]:pt;
		}
	}
	
	
	rt=(tmax[0]>tmax[1])?tmax[0]:tmax[1];
	printf("%f\n",rt);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld %ld",&(x[i]),&(y[i]),&(spd[i]));
   ^