#include <stdio.h>
#include <stdlib.h>

typedef enum{
	win,
	lose
}res;

int GCD(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return GCD(b, a % b);
	}
}

res judge(int *A, int N){
	int i, evennum = 0, onenum = 0, odd, gcd = A[0];
	for(i = 0; i < N; i++){
		gcd = GCD(A[i], gcd);
	}
	for(i = 0; i < N; i++){
		A[i] /= gcd;
		if(A[i] % 2 == 0){
			evennum++;
		}
		else if(A[i] == 1){
			onenum++;
		}
		else{
			odd = i;
		}
	}
	if(evennum % 2 == 1){
		return lose;
	}
	else if(evennum < N - 1 || onenum > 0){
		return win;
	}
	else{
		A[odd]--;
		return !judge(A, N);
	}
}

int main(){
	int N, i;
	scanf("%d", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	if(judge(A, N) == win){
		printf("Second\n");
	}
	else{
		printf("First\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:52:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^