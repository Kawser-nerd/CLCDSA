/*
AtCoder Regular Contest 024  ?? B - ?????
??:
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define max(x,y)(x<y?y:x)
#define int long long

int compare(const void *a, const void *b) {
	return *(int*)b - *(int*)a;
}

//???
//scanf("%d", &N);
//for (i; i < N; ++i) {
//	scanf("%d", &A[i]);
//	if (b[A[i]] == 1) {
//		ans = max(ans, i - j);
//		while (b[A[i]] == 1) {
//			b[A[j++]] = 0;
//		}
//	}
//	b[A[i]] = 1;
//}
//ans = max(ans, i - j);
//printf("%d\n", ans);

//????????
//static int N, i, j, ans;
//static int A, B;
//static char A[50][51];
//static int cnt, max;
//char *max_name;
//
//scanf("%d", &N);
//for (i = 0; i < N; i++) {
//	scanf("%s", A[i]);
//}
//max_name = A[0];
//for (i = 0; i < N; i++) {
//	cnt = 0;
//	for (j = 0; j < N; j++) {
//		if (strcmp(A[i], A[j]) == 0) {
//			cnt++;
//		}
//		if (cnt > max) {
//			max = cnt;
//			max_name = A[i];
//		}
//	}
//}
//printf("%s\n", max_name);

//#define DEBUG1
//#define DEBUG2
//#define DEBUGF

int main() {
	static int N, i, j, ans;
	//static int AN, BN, A[100] = {}, B[100] = {}, i, j, ans;
	//static int A, B;
	//static int A, B, C;
	static int a[1000000] = { 0 }, cnt = 0, cnt2 = 0;
	//static char A[50][51];
	static max = 0;
	//char *max_name;
	//static int ans;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		a[N + i] = a[i];
		cnt = cnt + a[i];
		if (i == N - 1 && cnt == 0 || cnt == N) {
			ans = -1;
		}
	}
	cnt = 0;

	if (ans != -1) {
		for (i = 0; i < 2 * N; i++) {
			if (a[i] == 0) {
				cnt++;
			}
			else if (i > 0 && a[i - 1] == 0 && a[i] == 0) {
				cnt++;
			}
			else if (a[i - 1] == 0 && a[i] == 1) {
				max = max(max, cnt);
				cnt = 0;
			}
		}
		for (i = 0; i < 2 * N; i++) {
			if (a[i] == 1) {
				cnt2++;
			}
			else if (i > 0 && a[i - 1] == 1 && a[i] == 1) {
				cnt2++;
			}
			else if (a[i - 1] == 1 && a[i] == 0) {
				max = max(max, cnt2);
				cnt2 = 0;
			}
		}
		ans = ((max - 1) / 2) + 1;
	}


	//ans = cnt;
	//qsort(A, N, sizeof(int), compare);

	//ans = ;
	printf("%d\n", ans);
	//printf("%s\n", max_name);

#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:70:9: warning: type defaults to ‘int’ in declaration of ‘max’ [-Wimplicit-int]
  static max = 0;
         ^
./Main.c:74:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
  scanf("%d", &N);
        ^
./Main.c:76:9: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
   scanf("%d", &a[i]);
         ^
./Main.c:118:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("%d\n", ans);
         ^
./Main.c:74:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:76:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^