/*
AtCoder Regular Contest A - BMI ??:
*/

#include<stdio.h>

//#define DEBUG1
//#define DEBUGF

int max(int a, int b) { return a >= b ? a : b; }

int main() {
	int;
	double h, b, ans;
	scanf("%lf %lf", &h, &b);
	ans = b * h/100 * h/100;
	printf("%.2f", ans);
#ifdef DEBUG1
	//printf("\n");
	//for (int i = 0; i < n; i++) {
	//	printf("%d\n", a[i]);
	//}
	/*??*/
	//printf("%s", str);
	//printf("\n");
#endif
#ifdef DEBUG1
	for (int i = 1; i <= n; i++) {
		scanf("%f", &MT[i]);
		scanf("%f", &mt[i]);
	}
	for (int i = 1; i < 6; i++) {
		printf(" %d", ans[i]);
	}
	printf("%d", ans);
	printf("\n");
#endif
#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: useless type name in empty declaration
  int;
  ^
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf %lf", &h, &b);
  ^