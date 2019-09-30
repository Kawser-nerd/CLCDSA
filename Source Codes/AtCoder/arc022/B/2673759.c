/*
AtCoder Regular Contest 021 b - ??????
??:
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define max(x,y)(x<y?y:x)
#define int long long

//#define DEBUG1
//#define DEBUG2
//#define DEBUGF

int main() {
	static int N, i, j, ans, A[100005], b[100005];
	scanf("%d", &N);
	for (i; i < N; ++i) {
		scanf("%d", &A[i]);
		if (b[A[i]] == 1) {
			ans = max(ans, i - j);
			while (b[A[i]] == 1) {
				b[A[j++]] = 0;
			}
		}
		b[A[i]] = 1;
	}
	ans = max(ans, i - j);
	printf("%d\n", ans);

#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
  scanf("%d", &N);
        ^
./Main.c:22:9: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
   scanf("%d", &A[i]);
         ^
./Main.c:32:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("%d\n", ans);
         ^
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^