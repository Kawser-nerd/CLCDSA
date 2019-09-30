/*
AtCoder Regular Contest 027 A - ??
??:
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

//#define DEBUG1
//#define DEBUG2
//#define DEBUGF

int main() {
	static int N, i, j, ans;
	//static int AN, BN, A[100] = {}, B[100] = {}, i, j, ans;
	static int A, B;
	//static int A, B, C;
	//static int a[31] = {}, b[31] = {}, cnt = 0;
	//static char A[50][51];
	//static int cnt, max;
	//char *max_name;
	//static int ans;

	scanf("%d %d", &A, &B);
	ans = 60 * (18 - A - 1) + (60 - B);
	printf("%d\n", ans);

#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &A, &B);
  ^