#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	int ans = a % p;
	return ans >= 0 ? ans : ans + p;
}

int power(int a, int N){
	if(N == 0){
		return 1;
	}
	else if(N % 2 == 0){
		return power(MOD(a * a), N / 2);
	}
	else{
		return MOD(a * power(a, N - 1));
	}
}

int inverse(int a){
	return power(a, p - 2);
}

signed main(){
	int N, T, i, ans = 0;
	scanf("%lld", &N);
	int *A = (int *)malloc(sizeof(int) * (N + 1));
	int *C = (int *)malloc(sizeof(int) * (N + 1));
	int *Qi = (int *)malloc(sizeof(int) * (N + 1));
	int *QT = (int *)malloc(sizeof(int) * (N + 1));
	for(i = 0; i <= N; i++){
		scanf("%lld", &A[i]);
	}
	scanf("%lld", &T);
	if(T <= N){
		printf("%lld\n", A[T]);
	}
	else{
		Qi[0] = 1;
		for(i = 1; i <= N; i++){
			Qi[0] = MOD(Qi[0] * (-i));
		}
		for(i = 1; i <= N; i++){
			Qi[i] = MOD(Qi[i - 1] * MOD(-i * inverse(N - i + 1)));
		}
		for(i = 0; i <= N; i++){
			C[i] = MOD(A[i] * inverse(Qi[i]));
		}
		QT[0] = 1;
		for(i = 0; i <= N; i++){
			QT[0] = MOD(QT[0] * (T - i));
		}
		for(i = 1; i <= N; i++){
			QT[i] = QT[i - 1];
		}
		for(i = 0; i <= N; i++){
			QT[i] = MOD(QT[i] * inverse(T - i));
		}
		for(i = 0; i <= N; i++){
			ans = MOD(ans + C[i] * QT[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^
./Main.c:37:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &T);
  ^