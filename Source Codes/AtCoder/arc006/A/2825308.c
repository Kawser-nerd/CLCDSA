#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int a, b, c, i, d = 0, e = 0;
	int x[6], y[6];
	for (i = 0; i < 6; i++) {
		scanf("%d", &x[i]);
	} scanf("%d", &b);
	for (i = 0; i < 6; i++) {
		scanf("%d", &y[i]);
	}
	for (i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (x[i] == y[j]) {
				d++;
			}
		}
	} if (d == 5) {
		for (i = 0; i < 6; i++) {
			if (y[i] == b) {
				e = 1;
			}
		}
	} if (e == 1) {
		printf("2\n");
	} else  if (d == 6){
		printf("1\n");
	} else  if (d == 5){
		printf("3\n");
	} else  if (d == 4){
		printf("4\n");
	} else  if (d == 3){
		printf("5\n");
	} else {
		printf("0\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &x[i]);
   ^
./Main.c:8:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  } scanf("%d", &b);
    ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &y[i]);
   ^