/*
AtCoder Regular Contest 023 A - ????
??:
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define max(x,y)(x<y?y:x)
#define int long long

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
	static int N, i, j;
	//static int A, B;
	static int A, B, C;
	//static char A[50][51];
	//static int cnt, max;
	//char *max_name;
	static int ans;

	scanf("%d %d %d", &A, &B, &C);
	//scanf("%d", &N);
	//for (i = 0; i < N; i++) {
	//	scanf("%s", A[i]);
	//}

	if ((B == 1) || (B == 2)) {
		A--;
		B += 12;
	}
	ans = 735369 - (365 * A + (int)(A / 4) - (int)(A / 100) + (int)(A / 400) + (int)((306 * (B + 1)) / 10) + C - 429);

	//ans = ;
	printf("%d\n", ans);
	//printf("%s\n", max_name);

#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:68:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
  scanf("%d %d %d", &A, &B, &C);
        ^
./Main.c:68:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘long long int *’ [-Wformat=]
./Main.c:68:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 4 has type ‘long long int *’ [-Wformat=]
./Main.c:81:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("%d\n", ans);
         ^
./Main.c:68:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &A, &B, &C);
  ^