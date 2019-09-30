#include <stdio.h>

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int C, N, M, L, Nmax = 0, Mmax = 0, Lmax = 0, max3, min3, i;
	scanf("%d", &C);
	for(i = 0; i < C; i++){
		scanf("%d%d%d", &N, &M, &L);
		max3 = max(N, max(M, L));
		min3 = min(N, min(M, L));
		Nmax = max(Nmax, max3);
		Mmax = max(Mmax, N + M + L - max3 - min3);
		Lmax = max(Lmax, min3);
	}
	printf("%d\n", Nmax * Mmax * Lmax);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &C);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &N, &M, &L);
   ^