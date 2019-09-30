#include<stdio.h>

int main(){
	int N, M, i;
	if(scanf("%d%d", &N, &M));
	for(i=N; i<=M/10000; i++){
		if(M%i==0){
			printf("%d\n", M/i);
			return 0;
		}
	}
	for(i=10000;; i--){
		if(M%i==0 && M/i>=N){
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}