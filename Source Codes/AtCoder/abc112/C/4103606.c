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

	for (int posY = 0; posY <= 100; posY++) {
		for (int posX = 0; posX <= 100; posX++) {
			//????????????????????
			//-1????????????0??????????
			//-2???????????
			int needH = -1;

			for (int i = 0; i < N; i++) {
				if (H[i] > 0) {
					//????????????posY,posX????
					//????????????????????
					int tmp = H[i] + abs(posY - Y[i]) + abs(posX - X[i]);
					if (needH == -1) {
						needH = tmp;
					}
					else {
						if (needH != tmp) {
							needH = -2;
							break;
						}
					}
				}
			}
			//?????????????
			if (needH == -2) {
				continue;
			}
			for (int i = 0; i < N; i++) {
				//???0??????????????
				if (H[i] == 0) {
					int dist = abs(posY - Y[i]) + abs(posX - X[i]);
					if (needH > dist) {
						needH = -2;
						break;
					}
				}
			}
			//?????????????
			if (needH == -2) continue;
			//?????????????????
			printf("%d %d %d", posX, posY, needH);
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
./Main.c:24:23: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
      int tmp = H[i] + abs(posY - Y[i]) + abs(posX - X[i]);
                       ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &X[i], &Y[i], &H[i]);
   ^