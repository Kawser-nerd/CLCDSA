#include <stdio.h>

int Y, M, D;

int DinM(){
	if(M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12){
		return 31;
	}
	else if(M == 4 || M == 6 || M == 9 || M == 11){
		return 30;
	}
	else{
		if(Y % 4 != 0 || (Y % 100 == 0 && Y % 400 != 0)){
			return 28;
		}
		else{
			return 29;
		}
	}
}

void plus(){
	if(D < DinM()){
		D++;
	}
	else if(M < 12){
		M++;
		D = 1;
	}
	else{
		Y++;
		M = 1;
		D = 1;
	}
}

int main(){
	scanf("%d/%d/%d", &Y, &M, &D);
	while(1){
		if(Y % (M * D) == 0){
			printf("%04d/%02d/%02d\n", Y, M, D);
			return 0;
		}
		else{
			plus();
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:38:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d/%d/%d", &Y, &M, &D);
  ^