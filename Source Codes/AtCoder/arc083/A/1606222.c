#include <stdio.h>
#include <stdlib.h>

int main(){
	int A, B, C, D, E, F, i, j, k, a, b;
	scanf("%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F);
	int *AB = (int *)malloc(sizeof(int) * (F + 1));
	int *CD = (int *)malloc(sizeof(int) * (F + 1));
	for(i = 0; i <= F; i++){
		AB[i] = 0;
		CD[i] = 0;
	}
	for(i = 0; 100 * i * A <= F; i++){
		for(j = 0; 100 * j * B <= F; j++){
			if(100 * (i * A + j * B) <= F){
				AB[100 * (i * A + j * B)] = 1;
			}
		}
	}
	for(i = 0; i * C <= F; i++){
		for(j = 0; j * D <= F; j++){
			if(i * C + j * D <= F){
				CD[i * C + j * D] = 1;
			}
		}
	}
/*	printf("AB:\n");
	for(i = 0; i <= F; i++){
		printf("%d ", AB[i]);
	}
	printf("\n");
	printf("CD:\n");
	for(i = 0; i <= F; i++){
		printf("%d ", CD[i]);
	}
	printf("\n");
*/	a = 100 * A;
	b = 0;
	for(i = 0; i <= F; i++){
		for(j = 0; j <= F; j++){
			if((i > 0 || j > 0) && AB[i] == 1 && CD[j] == 1 && (i + j) * b < (a + b) * j && i + j <= F && i * E >= 100 * j){
//				printf("(i, j) = (%d, %d)\n", i, j);
				a = i;
				b = j;
			}
		}
	}
	printf("%d %d\n", a + b, b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F);
  ^