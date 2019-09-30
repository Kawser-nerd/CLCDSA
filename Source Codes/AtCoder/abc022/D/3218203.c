#include <stdio.h>
#include <math.h>

double Ax[100005];
double Ay[100005];
double Bx[100005];
double By[100005];

double dist(double x,double y){
return sqrt((x*x)+(y*y));
}
double max(double a,double b){
	if(a>b){return a;}
	else{return b;}
}

int main(){

	int N;

	scanf("%d",&N);

	int i;

	double g1_x=0;
	double g1_y=0;
	double g2_x=0;
	double g2_y=0;

	for(i=0;i<N;i++){
	scanf("%lf %lf",&Ax[i],&Ay[i]);
	g1_x+=Ax[i];
	g1_y+=Ay[i];
	}
	for(i=0;i<N;i++){
	scanf("%lf %lf",&Bx[i],&By[i]);
	g2_x+=Bx[i];
	g2_y+=By[i];
	}

	g1_x/=(double)N;
	g1_y/=(double)N;
	g2_x/=(double)N;
	g2_y/=(double)N;

	double da=0;
	double db=0;

	for(i=0;i<N;i++){
		da=max(da,dist(g1_x-Ax[i],g1_y-Ay[i]));
		db=max(db,dist(g2_x-Bx[i],g2_y-By[i]));
	}

	printf("%.12f\n",db/da);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf %lf",&Ax[i],&Ay[i]);
  ^
./Main.c:36:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf %lf",&Bx[i],&By[i]);
  ^