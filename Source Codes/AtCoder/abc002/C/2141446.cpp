#include <stdio.h>

int main(){

	int xa,xb,xc,ya,yb,yc;
	scanf( "%d%d%d%d%d%d", &xa,&ya, &xb, &yb, &xc, &yc );
	xb -= xa;
	xc -= xa;
	yb -= ya;
	yc -= ya;
	
	double ret = ( xb * yc - yb * xc ) / 2.0;
	ret = ret > 0 ? ret : -1 * ret;

	printf("%f\n", ret);

}