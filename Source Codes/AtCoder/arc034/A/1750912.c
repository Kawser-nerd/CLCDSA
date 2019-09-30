#include <stdio.h>

int main(void) {
	double t=0.0,a,b,c,d,e;
	int i,n;
	scanf("%d",&n);
	
	for(i=0;i<n;i++) {
		scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&d,&e);
		if((a+b+c+d+e*110/900)>=t) {
			t=a+b+c+d+e*110/900;
		}
	}
	printf("%f\n",t);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&d,&e);
   ^