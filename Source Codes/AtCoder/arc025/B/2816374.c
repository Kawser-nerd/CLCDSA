/*
AtCoder Regular Contest 025 B - ??????
??: mi
*/

//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//#include<stdlib.h>
//
//#define max(x,y)(x<y?y:x)
//#define int long long
//
//int compare(const void *a, const void *b) {
//	return *(int*)b - *(int*)a;
//}
//
////???
////scanf("%d", &N);
////for (i; i < N; ++i) {
////	scanf("%d", &A[i]);
////	if (b[A[i]] == 1) {
////		ans = max(ans, i - j);
////		while (b[A[i]] == 1) {
////			b[A[j++]] = 0;
////		}
////	}
////	b[A[i]] = 1;
////}
////ans = max(ans, i - j);
////printf("%d\n", ans);
//
////????????
////static int N, i, j, ans;
////static int A, B;
////static char A[50][51];
////static int cnt, max;
////char *max_name;
////
////scanf("%d", &N);
////for (i = 0; i < N; i++) {
////	scanf("%s", A[i]);
////}
////max_name = A[0];
////for (i = 0; i < N; i++) {
////	cnt = 0;
////	for (j = 0; j < N; j++) {
////		if (strcmp(A[i], A[j]) == 0) {
////			cnt++;
////		}
////		if (cnt > max) {
////			max = cnt;
////			max_name = A[i];
////		}
////	}
////}
////printf("%s\n", max_name);
//
////#define DEBUG1
////#define DEBUG2
//#define DEBUGF
//
//int main() {
//	//static int N, i, j, ans;
//	static int AN, BN, A[100] = {}, B[100] = {}, i, j, ans;
//	//static int A, B;
//	//static int A, B, C;
//	static int a[31] = {}, b[31] = {}, cnt = 0;
//	//static char A[50][51];
//	//static int cnt, max;
//	//char *max_name;
//	//static int ans;
//
//	scanf("%d %d", &AN, &BN);
//	for (i = 0; i < AN; i++) {
//		scanf("%d", A[i]);
//		a[A[i]]++;
//	}
//	for (i = 0; i < BN; i++) {
//		scanf("%d", B[i]);
//		b[B[i]]++;
//	}
//	for (i = 0; i < 100; i++) {
//		cnt = cnt + min(a[A[i]], b[B[i]]);
//	}
//	ans = cnt;
//	//qsort(A, N, sizeof(int), compare);
//
//	//ans = ;
//	printf("%d\n", ans);
//	//printf("%s\n", max_name);
//
//#ifdef DEBUGF
//	getch();
//#endif
//	return 0;
//}

#include<stdio.h>
int MAX(int a, int b) { return a<b ? b : a; }
int main() {
	int h, w, i, j, k, l, d[110][110], max;
	scanf("%d %d", &h, &w);
	for (i = 0; i<h; i++) {
		for (j = 0; j<w; j++) {
			scanf("%d", &k);
			d[i + 1][j + 1] = (i + j) % 2 ? -k : k;
		}
	}
	for (i = 0; i<h; i++) {
		for (j = 0; j<w; j++)d[i + 1][j + 1] += d[i][j + 1] + d[i + 1][j] - d[i][j];
	}
	for (i = max = 0; i<h; i++) {
		for (j = 0; j<w; j++) {
			for (k = i; k<h; k++) {
				for (l = j; l<w; l++) {
					if (d[k + 1][l + 1] + d[i][j] == d[k + 1][j] + d[i][l + 1])max = MAX(max, (k + 1 - i)*(l + 1 - j));
				}
			}
		}
	}
	printf("%d\n", max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:103:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &h, &w);
  ^
./Main.c:106:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &k);
    ^