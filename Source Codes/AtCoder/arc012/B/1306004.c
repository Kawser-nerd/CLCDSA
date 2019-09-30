#include <stdio.h>
int main(void)
{
	int n;
	double a,b,l,t;
	scanf("%d%lf%lf%lf",&n,&a,&b,&l);
	while(n-->0){
		t=l/a;
		l=b*t;
	}
	printf("%.10lf\n",l);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%lf%lf%lf",&n,&a,&b,&l);
  ^