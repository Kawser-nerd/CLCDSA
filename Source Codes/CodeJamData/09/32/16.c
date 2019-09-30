#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long double center_mass(int *pos,int *spe,long double t,int N) {
	long double res;
	long double X=0,Y=0,Z=0;
	int i;
	for(i=0;i<N;i++) {
		X+=pos[3*i]+spe[3*i]*t;
		Y+=pos[3*i+1]+spe[3*i+1]*t;
		Z+=pos[3*i+2]+spe[3*i+2]*t;
	}
	res=sqrt(X*X+Y*Y+Z*Z)/(long double)N;
	return res;
}

long double find_t(int *pos,int *spe,int N) {
	long double res;
	int X=0,Y=0,Z=0,VX=0,VY=0,VZ=0,i;
	for(i=0;i<N;i++) {
		X+=pos[3*i];
		VX+=spe[3*i];
		Y+=pos[3*i+1];
		VY+=spe[3*i+1];
		Z+=pos[3*i+2];
		VZ+=spe[3*i+2];
	}
	if(VX*VX+VY*VY+VZ+VZ==0)
		return 0;
	res=-(long double)(VX*X+VY*Y+VZ*Z)/(long double)(VX*VX+VY*VY+VZ*VZ);
	return res;
}		


int main() {
	int T,N,ca,i,j,k;
	int *pos;
	int *spe;
	long double t;
	scanf("%d ",&T);
	for(ca=1;ca<=T;ca++) {
		scanf("%d ",&N);
		pos=(int*)malloc(3*N*sizeof(int));
		spe=(int*)malloc(3*N*sizeof(int));
		for(i=0;i<N;i++) {
			scanf("%d ",pos+3*i);
			scanf("%d ",pos+3*i+1);
			scanf("%d ",pos+3*i+2);
			scanf("%d ",spe+3*i);
			scanf("%d ",spe+3*i+1);
			scanf("%d ",spe+3*i+2);
		}
		t=find_t(pos,spe,N);
		if(t<=0)
			t=0;
		printf("Case #%d: %Lf %Lf\n",ca,center_mass(pos,spe,t,N),t);
		free(pos);
		free(spe);		
	}	
	return 0;
}
