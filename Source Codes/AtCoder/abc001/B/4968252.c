#include<stdio.h>
int main(){
	int m;
	scanf("%d",&m);
	double km = m/1000.0;
	int vv;
	if(km<0.1)		vv=0;
	else if(km<=5)	vv = m/100;
	else if(km<=30)	vv = (int)km+50;
	else if(km<=70)	vv = (km-30)/5+80;
	else			vv = 89;
	if(vv<10)	printf("0");
	printf("%d\n",vv);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&m);
  ^