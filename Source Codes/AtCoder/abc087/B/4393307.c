#include <stdio.h>

int main(void){

	int A, B, C, X;

	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	scanf("%d", &X);

	int count = 0;
	int i, j;

	if( X % 50 != 0){
		
		printf("%d\n", count);
	
	}else{
		
		for(i = 0; i <= X/500; i++){
			if(i <= A){
				int rest1 = X - 500 * i;
				for(j = 0; j <= rest1/100; j++){
					int rest2 = rest1 - 100 * j;
					if(j <= B){
						int rest3 = rest2 / 50;
						if(rest3 <= C){
							count++;
						}
					}
				}
			}
		}
		printf("%d\n", count);	
	}	


} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &A);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &B);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &C);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &X);
  ^