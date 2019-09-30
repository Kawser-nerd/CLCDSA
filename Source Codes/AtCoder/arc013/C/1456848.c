#include <stdio.h>

#define inf (int)(1e9 + 1)

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
	int N, X, Y, Z, M, x, y, z, xmax, xmin, ymax, ymin, zmax, zmin, grundy = 0, i, j;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d%d%d", &X, &Y, &Z);
		scanf("%d", &M);
		xmax = 0;
		xmin = inf;
		ymax = 0;
		ymin = inf;
		zmax = 0;
		zmin = inf;
		for(j = 0; j < M; j++){
			scanf("%d%d%d", &x, &y, &z);
			xmax = max(x, xmax);
			xmin = min(x, xmin);
			ymax = max(y, ymax);
			ymin = min(y, ymin);
			zmax = max(z, zmax);
			zmin = min(z, zmin);
		}
		grundy ^= X - xmax - 1;
		grundy ^= xmin;
		grundy ^= Y - ymax - 1;
		grundy ^= ymin;
		grundy ^= Z - zmax - 1;
		grundy ^= zmin;
	}
	if(grundy == 0){
		printf("LOSE\n");
	}
	else{
		printf("WIN\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &X, &Y, &Z);
   ^
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &M);
   ^
./Main.c:36:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d%d", &x, &y, &z);
    ^