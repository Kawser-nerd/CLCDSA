/*
AtCoder Regular Contest 017 B - ??????? ??:
*/

#include<stdio.h>

//#define DEBUG1
//#define DEBUGF

int max(int a, int b) { return a >= b ? a : b; }

int main() {
	int ;
	int n, k,a, z = 400000, length = 0, ans = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a > z) {
				length++;
			if (length >= k) {
				ans++;
			}
		}
		else {
			length = 1;
		}
		z = a;
	}
	if (k == 1) {
		printf("%d", n);
		printf("\n");
	}
	else {
		printf("%d", ans);
		printf("\n");
	}
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
	/*	for (int i = 1; i <= n; i++) {
	scanf("%f", &MT[i]);
	scanf("%f", &mt[i]);
	}
	for (int i = 1; i < 6; i++) {
	printf(" %d", ans[i]);
	}
	printf("%d", ans);
	printf("\n")*/;
#endif
#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: useless type name in empty declaration
  int ;
  ^
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &k);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^