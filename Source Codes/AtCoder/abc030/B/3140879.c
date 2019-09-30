#include <stdio.h>

double max(double a,double b){
	if(a>b){return a;}
	else{return b;}
}

int main(){

	int n,m;

	scanf("%d %d",&n,&m);

	int hour=0;
	int min=0;

	double tyousin=0;
	double tansin=0;

	while(1){	
		if(hour==n&&min==m){break;}
		tyousin+=6.0;
		tansin+=0.5;
		if(tyousin==360.0){tyousin=0;}
		if(tansin==360.0){tansin=0;}
		if(min+1==60){
		hour++;
		min=0;
		}
		else{
		min++;
		}
	}

	double ans=max(tansin-tyousin,tyousin-tansin);

	if(ans>180.0){ans=360.0-ans;}

	printf("%.6f\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^