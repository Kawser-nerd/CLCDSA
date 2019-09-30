#include <stdio.h>
 
int main(){
	int i, N;
	double sum = 0, sa, T;
	double t[200001];
 
	scanf("%d %lf", &N, &T);
 
	for(i = 1; i <= N; i++) {
		scanf("%lf", &t[i]);
	}
 
	for(i = 1; i < N; i++) {
		sa = t[i + 1] - t[i];
		if(sa >= T) {
			sum += T;
		}
		if(sa < T) {
			sum += sa;
		}
	}
        sum += T;
	printf("%d", (int)sum);
 
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %lf", &N, &T);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf", &t[i]);
   ^