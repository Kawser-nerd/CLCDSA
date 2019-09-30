#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
?? time_m(X,Y):= \max c_i*max(|x_i-X|,|y_i-Y|)?????????
*/

int N;
int x[1000],y[1000],c[1000];

double a(double X){
	if(X>0){return X;}else{return -X;}
}

double time_m(double X, double Y){
	int i;
	double m;
	m=0;
	for(i=0;i<N;i++){
		if(m<c[i]*a(x[i]-X)){m =c[i]*a(x[i]-X);}
		if(m<c[i]*a(y[i]-Y)){m =c[i]*a(y[i]-Y);}
	}

	return m;

}

int main(void){
	int i;
	double xmax,xmin,ymax,ymin;
	double d[4];
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d %d", &x[i],&y[i],&c[i]);
	}
	xmin=-100000;
	xmax= 100000;
	ymin=-100000;
	ymax= 100000;

	while(xmax-xmin>0.0000001 || ymax-ymin>0.0000001){
		d[0] = time_m((  xmax+2*xmin)/3,(  ymax+2*ymin)/3);
		d[1] = time_m((2*xmax+  xmin)/3,(  ymax+2*ymin)/3);
		d[2] = time_m((  xmax+2*xmin)/3,(2*ymax+  ymin)/3);
		d[3] = time_m((2*xmax+  xmin)/3,(2*ymax+  ymin)/3);
		if(d[0]>=d[1] && d[2]>=d[3]){
			xmin = (xmax+2*xmin)/3;
		}else if(d[1]>=d[0] && d[3]>=d[2]){
			xmax = (2*xmax+xmin)/3;
		}

		if(d[0]>=d[2] && d[1]>=d[3]){
			ymin = (ymax+2*ymin)/3;
		}else if(d[2]>=d[0] && d[3]>=d[1]){
			ymax = (2*ymax+ymin)/3;
		}

	}
	printf("%.10f",time_m(xmax,ymax));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &x[i],&y[i],&c[i]);
   ^