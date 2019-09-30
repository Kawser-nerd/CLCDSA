#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	double x;
	double y;
}pos;

double max(double a, double b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int N, i, X, Y;
	scanf("%d", &N);
	pos *A = (pos *)malloc(sizeof(pos) * N);
	pos *B = (pos *)malloc(sizeof(pos) * N);
	pos centA, centB;
	centA.x = 0;
	centA.y = 0;
	centB.x = 0;
	centB.y = 0;
	for(i = 0; i < N; i++){
		scanf("%d%d", &X, &Y);
		A[i].x = (double)X;
		A[i].y = (double)Y;
		centA.x += A[i].x / N;
		centA.y += A[i].y / N;
	}
	for(i = 0; i < N; i++){
		scanf("%d%d", &X, &Y);
		B[i].x = (double)X;
		B[i].y = (double)Y;
		centB.x += B[i].x / N;
		centB.y += B[i].y / N;
	}
	double max_disA = 0, max_disB = 0;
	for(i = 0; i < N; i++){
		max_disA = max(max_disA, sqrt((A[i].x - centA.x) * (A[i].x - centA.x) + (A[i].y - centA.y) * (A[i].y - centA.y)));
		max_disB = max(max_disB, sqrt((B[i].x - centB.x) * (B[i].x - centB.x) + (B[i].y - centB.y) * (B[i].y - centB.y)));
	}
	printf("%.12f\n", max_disB / max_disA);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &X, &Y);
   ^
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &X, &Y);
   ^