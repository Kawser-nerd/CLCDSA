#include<stdio.h>

int main(){
	int N, M, i;
	if(scanf("%d%d", &N, &M));
	for(i=N; i<=M/10; i++){
		if(M%i==0){
			printf("%d\n", M/i);
			return 0;
		}
	}
	if(M%20==0 && M/19>=N){printf("19\n");return 0;}
	if(M%19==0 && M/19>=N){printf("19\n");return 0;}
	if(M%18==0 && M/18>=N){printf("18\n");return 0;}
	if(M%17==0 && M/17>=N){printf("17\n");return 0;}
	if(M%16==0 && M/16>=N){printf("16\n");return 0;}
	if(M%15==0 && M/15>=N){printf("15\n");return 0;}
	if(M%14==0 && M/14>=N){printf("14\n");return 0;}
	if(M%13==0 && M/13>=N){printf("13\n");return 0;}
	if(M%12==0 && M/12>=N){printf("12\n");return 0;}
	if(M%11==0 && M/11>=N){printf("11\n");return 0;}
	if(M%10==0 && M/10>=N){printf("10\n");return 0;}
	if(M%9==0 && M/9>=N){printf("9\n");return 0;}
	if(M%8==0 && M/8>=N){printf("8\n");return 0;}
	if(M%7==0 && M/7>=N){printf("7\n");return 0;}
	if(M%6==0 && M/6>=N){printf("6\n");return 0;}
	if(M%5==0 && M/5>=N){printf("5\n");return 0;}
	if(M%4==0 && M/4>=N){printf("4\n");return 0;}
	if(M%3==0 && M/3>=N){printf("3\n");return 0;}
	if(M%2==0 && M/2>=N){printf("2\n");return 0;}
	printf("1\n");
	return 0;
}