#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, i, eq, ans = 0;
	char * A = (char *)malloc(sizeof(char) * 300001);
	scanf("%s", A);
	for(N = 0; A[N] != '\0'; N++){}
	for(i = 0, eq = 0; i < N; i++){
		if(A[i] == A[N - 1 - i]){
			eq++;
		}
	}
	for(i = 0; i < N; i++){
		if(2 * i + 1 == N){
			if(eq != N){
				ans += 25;
			}
		}
		else{
			if(A[i] == A[N - 1 - i]){
				ans += 25;
			}
			else{
				if(eq == N - 2){
					ans += 24;
				}
				else{
					ans += 25;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", A);
  ^