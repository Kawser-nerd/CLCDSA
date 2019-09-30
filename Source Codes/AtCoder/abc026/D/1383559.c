#include <stdio.h>
#include <math.h>

int main(){
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	double l, h, r;
	for(l = 0, r = 201; r - l > 1e-12;){
		h = (l + r) / 2;
		if(A * h + B * sin(C * h * M_PI) > 100){
			r = h;
		}
		else{
			l = h;
		}
	}
	printf("%.10f\n", l);
	//printf("%.10f\n", A * l + B * sin(C * l * M_PI));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &A, &B, &C);
  ^