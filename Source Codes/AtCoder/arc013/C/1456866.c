#include <stdio.h>

int main(){
	int N, X, Y, Z, M, x, y, z, xmax, xmin, ymax, ymin, zmax, zmin, grundy = 0, i, j;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d%d%d%d", &X, &Y, &Z, &M);
		scanf("%d%d%d", &xmax, &ymax, &zmax);
		xmin = xmax;
		ymin = ymax;
		zmin = zmax;
		for(j = 1; j < M; j++){
			scanf("%d%d%d", &x, &y, &z);
			if(x > xmax){
				xmax = x;
			}
			else if(x < xmin){
				xmin = x;
			}
			if(y > ymax){
				ymax = y;
			}
			else if(y < ymin){
				ymin = y;
			}
			if(z > zmax){
				zmax = z;
			}
			else if(z < zmin){
				zmin = z;
			}
		}
		grundy ^= (X - xmax - 1) ^ xmin ^ (Y - ymax - 1) ^ ymin ^ (Z - zmax - 1) ^ zmin;
	}
	if(grundy == 0){
		printf("LOSE\n");
	}
	else{
		printf("WIN\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d", &X, &Y, &Z, &M);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &xmax, &ymax, &zmax);
   ^
./Main.c:13:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d%d", &x, &y, &z);
    ^