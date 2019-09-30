#include <stdio.h>

double min(double a, double b){
	return a <= b ? a : b;
}

int main(){
	int L, X, Y, S, D;
	scanf("%d%d%d%d%d", &L, &X, &Y, &S, &D);
	if(X >= Y){
		printf("%.12lf\n", (double)((D - S + L) % L) / (X + Y));
	}
	else{
		printf("%.12lf\n", min((double)((D - S + L) % L) / (X + Y), (double)((S - D + L) % L) / (Y - X)));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d%d", &L, &X, &Y, &S, &D);
  ^