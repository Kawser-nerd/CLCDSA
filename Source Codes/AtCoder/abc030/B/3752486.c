#include<stdio.h>
int n, m;
double a;
int main(){
	scanf("%d%d", &n, &m);
	a = n%12*60+m-m*12;
	if(a<0){a=-a;}
	if(a>360){a=720-a;}
	a /= 2;
	printf("%f\n", a);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &n, &m);
  ^