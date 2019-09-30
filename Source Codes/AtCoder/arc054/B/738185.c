#include<stdio.h>
#include <math.h>
int main(){
	long double kiroku=-1.0;
	long double kari;
	long double x;
	long double P;
	scanf("%Lf",&P);
	kiroku=P;
	for(x=0.00001;;x+=0.00001){
		kari=x+P/pow(2,x/1.5);
		if(kari<kiroku){
			kiroku=kari;
				}
		else {
			if(x>=0.00001){x-=0.00001;}
			break;
		}
	}
	for(;;x+=0.00000001){
		kari=x+P/pow(2,x/1.5);
		if(kari<kiroku){
			kiroku=kari;
				}
		else {
			if(x>=0.00000001){x-=0.00000001;}
			break;
		}
	}
	for(;;x+=0.0000000001){
		kari=x+P/pow(2,x/1.5);
		if(kari<kiroku){
			kiroku=kari;
		}
		else break;
	}
	printf("%.12Lf\n",x+P/pow(2,x/1.5));
return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%Lf",&P);
  ^