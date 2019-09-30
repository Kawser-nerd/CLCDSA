#include <stdio.h>

int main(){
	long int N, M;
	scanf("%ld %ld",&N, &M);

	long int a[N], b[N];
	int flag[2][N];
	int k = 0;
	for(int i = 0; i < N; i++){
		flag[0][i] = 0;
		flag[1][i] = 0;
	}
	for(int i = 0; i < M; i++){
		long long int buf1, buf2;
		scanf("%ld %ld", &buf1, &buf2);
		if(buf1 == 1){
			a[k] = buf1;
			b[k] = buf2;
			flag[0][b[k]-1] = 1;
			k++;
		} else if(buf2 == N) {
			a[k] = buf1;
			b[k] = buf2;
			flag[1][a[k]-1] = 1;
			k++;
		}
	}

	for(int i = 0; i < M; i++){
		if(flag[0][i] == 1 && flag[1][i] == 1){
			printf("POSSIBLE\n");
			return 0;
		}
	}

	printf("IMPOSSIBLE\n");

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:9: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
   scanf("%ld %ld", &buf1, &buf2);
         ^
./Main.c:16:9: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 3 has type ‘long long int *’ [-Wformat=]
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld",&N, &M);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld", &buf1, &buf2);
   ^