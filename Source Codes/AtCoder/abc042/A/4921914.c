#include <stdio.h>

int main(void){
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	int number[3] = {A, B, C};
	int answer[3] = {5, 5, 7};
	
	int i, j, tmp;
	
	for (i=0; i<3; i++){
		for (j=i+1; j<3; j++){
			if (number[i] > number[j]){
				tmp = number[i];
				number[i] = number[j];
				number[j] = tmp;
			}
		}
	}

	if (number[0] == 5 && number[1] == 5 && number[2] == 7){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &A, &B, &C);
  ^