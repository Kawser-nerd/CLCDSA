#include<stdio.h>

int main(){
	int N, M, i;
	if(scanf("%d%d", &N, &M));
	for(i=N; i<=M/4; i++){
		if(M%i==0){
			printf("%d\n", M/i);
			return 0;
		}
	}
	if(M%3==0 && M/3>=N){
		printf("3\n");
		return 0;
	}
	if(M%2==0 && M/2>=N){
		printf("2\n");
		return 0;
	}
	printf("1\n");
	return 0;
}