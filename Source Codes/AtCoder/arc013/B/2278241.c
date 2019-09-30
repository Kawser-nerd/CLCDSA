/*
AtCoder Regular Contest 013  B - ????????? ??:AC(????AC????????????????)
*/

#include<stdio.h>

//#define DEBUG1
//#define DEBUGF

//int max(int a, int b) {
//	return a >= b ? a : b;
//}

int main() {
	int c, tmp, ans = 0;
	int a[100][3];
	int b[3] = {0, 0, 0};
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	}
#ifdef DEBUG1
	printf("%d", c);
	printf("\n");
	for (int i = 0; i < c; i++) {
		printf("%d %d %d", a[i][0], a[i][1], a[i][2]);
		printf("\n");
	}
#endif
	for (int i = 0; i < c; i++) {
		if (a[i][0] < a[i][1]) {
			tmp = a[i][0];
			a[i][0] = a[i][1];
			a[i][1] = tmp;
		}
		if (a[i][0] < a[i][2]) {
			tmp = a[i][0];
			a[i][0] = a[i][2];
			a[i][2] = tmp;
		}
		if (a[i][1] < a[i][2]) {
			tmp = a[i][1];
			a[i][1] = a[i][2];
			a[i][2] = tmp;
		}
		if (a[i][0] > b[0]) {
			b[0] = a[i][0];
		}
		if (a[i][1] > b[1]) {
			b[1] = a[i][1];
		}
		if (a[i][2] > b[2]) {
			b[2] = a[i][2];
		}
	}
	ans = b[0] * b[1] * b[2];

	printf("%d\n", ans);
#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &c);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
   ^