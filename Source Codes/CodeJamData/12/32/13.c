#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve();

int T;

int main(void){
	int i;

	scanf("%d",&T);

	for(i=0;i<T;i++){
		printf("Case #%d:\n",i+1);
		solve();
	}

	return 0;
}

void solve(){
	int N,A,i;
	double D;
	double other[2000][2];
	double acc[250];
	double t;
	double d;
	double other_vel;
	double other_t;
	double d_init;

	scanf("%lf %d %d",&D,&N,&A);
	
	for(i=0;i<N;i++)
		scanf("%lf %lf",&other[i][0],&other[i][1]);
	for(i=0;i<A;i++)
		scanf("%lf",&acc[i]);
	
	if(N==1){
		other[1][1] = other[0][1];
		other[1][0] = other[0][0];
		other[0][1] = 0;
		other[0][0] = 0;
	}
	other_vel=(other[1][1]-other[0][1])/(other[1][0]-other[0][0]);
	d_init = other[0][1];
	for(i=0;i<A;i++){
		t = sqrt((D*2)/acc[i]);
		other_t = (D-d_init)/other_vel;
		if(t>other_t){
			printf("%lf\n",t);
		}
		else{
			d = 2*pow(other_vel,2)/acc[i];
			t = d/other_vel;
			other_t = (D-d)/other_vel;
			printf("%lf\n",(D-d_init)/other_vel);
		}

	}



	return;
}
