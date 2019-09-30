/*
AtCoder Regular Contest 015 B - ???????? ??:
*/

#include<stdio.h>

//#define DEBUG1
//#define DEBUGF

int max(int a, int b) { return a >= b ? a : b; }

int main() {
	int n;
	float MT[3650], mt[3650];
	int ans[6] = {0,0,0,0,0,0};
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%f", &MT[i]);
		scanf("%f", &mt[i]);
		if (MT[i] >= 35.0)ans[0]++;
		if (30.0 <= MT[i] && MT[i]<35.0)ans[1]++;
		if (25.0 <= MT[i] && MT[i]<30.0)ans[2]++;
		if (mt[i] >= 25.0)ans[3]++;
		if (mt[i]<0 && MT[i] >= 0)ans[4]++;
		if (MT[i]<0)ans[5]++;
	}
//#ifdef DEBUG1
//	for (int i = 1; i <= n; i++) {
//		printf("%f\n", MT[i]);
//		printf("%f\n", mt[i]);
//	}
//#endif


	/*??*/
	printf("%d", ans[0]);
	for (int i = 1; i < 6; i++) {
		printf(" %d", ans[i]);
	}
	printf("\n");
#ifdef DEBUG1
#endif
#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%f", &MT[i]);
   ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%f", &mt[i]);
   ^