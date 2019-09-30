#include<stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	int *X = (int *)malloc(sizeof(int)*N);
	int *Y = (int *)malloc(sizeof(int)*N);
	int *H = (int *)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &X[i], &Y[i], &H[i]);
	}

	for (int posx = 0; posx <= 100; posx++) {
		for (int posy = 0; posy <= 100; posy++) {
			int needH = -1;
			for (int i = 0; i < N; i++) {
				if (H[i] > 0) {
					int tmp1 = H[i] + abs(X[i] - posx) + abs(Y[i] - posy);
					if (needH == -1) {
						needH = tmp1;
					}
					else if (needH != tmp1) {
						needH = -2;
						break;
					}
				}
			}
			if (needH == -2) {
				continue;
			}
			for (int i = 0; i < N; i++) {
				if (H[i] == 0) {
					int tmp2 = abs(X[i] - posx) + abs(Y[i] - posy);
					if (needH == -1) {
						needH = tmp2;
					}
					else if (needH > tmp2) {
						needH = -2;
						break;
					}
				}
			}
			if (needH == -2) {
				continue;
			}
			printf("%d %d %d", posx, posy, needH);
			printf("\n");
			return 0;
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:6:18: warning: implicit declaration of function ‘malloc’ [-Wimplicit-function-declaration]
  int *X = (int *)malloc(sizeof(int)*N);
                  ^
./Main.c:6:18: warning: incompatible implicit declaration of built-in function ‘malloc’
./Main.c:6:18: note: include ‘<stdlib.h>’ or provide a declaration of ‘malloc’
./Main.c:18:24: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
      int tmp1 = H[i] + abs(X[i] - posx) + abs(Y[i] - posy);
                        ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &X[i], &Y[i], &H[i]);
   ^