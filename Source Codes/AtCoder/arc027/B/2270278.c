#include <stdio.h>
#include <stdlib.h>
#define int long long

int is_alf(char C){
	if((int)'A' <= (int)C && (int)C  <= (int)'Z'){
		return 1;
	}
	else{
		return 0;
	}
}

int power(int a, int N){
	if(N == 0){
		return 1;
	}
	else{
		return a * power(a, N - 1);
	}
}

signed main(){
	int N, i, j;
	char nowC;
	scanf("%lld", &N);
	char *S1 = (char *)malloc(sizeof(char) * (N + 1));
	char *S2 = (char *)malloc(sizeof(char) * (N + 1));
	scanf("%s", S1);
	scanf("%s", S2);
	for(i = 0; i < N; i++){
		if(is_alf(S1[i]) == 0){
			if(is_alf(S2[i]) == 1){
				nowC = S2[i];
				for(j = 0; j < N; j++){
					if(S1[j] == nowC){
						S1[j] = S1[i];
					}
					if(S2[j] == nowC){
						S2[j] = S1[i];
					}
				}
			}
		}
		else{
			nowC = S1[i];
			for(j = 0; j < N; j++){
				if(S1[j] == nowC){
					S1[j] = S2[i];
				}
				if(S2[j] == nowC){
					S2[j] = S2[i];
				}
			}
		}
	}
	int *A = (int *)malloc(sizeof(int) * 26);
	for(i = 0; i < 26; i++){
		A[i] = 0;
	}
	for(i = 0; i < N; i++){
		if(is_alf(S1[i]) == 1){
			A[(int)S1[i] - (int)'A'] = 1;
		}
	}
	int sum = 0, ans;
	for(i = 0; i < 26; i++){
		sum += A[i];
	}
//	printf("%s\n", S1);
//	printf("%s\n", S2);
//	printf("sum = %lld\n", sum);
	if(is_alf(S1[0]) == 1){
		ans = 9 * power(10, sum - 1);
	}
	else{
		ans = power(10, sum);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S1);
  ^
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S2);
  ^