/*
AtCoder Regular Contest 021 B - ??????
??:
*/

//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//#include<stdlib.h>
//
//#define DEBUG1
//#define DEBUG2
//#define DEBUGF
//
//#ifdef DEBUG1
//#ifdef DEBUG2
//#ifdef DEBUGF
//#endif
//#define int long long

#include<stdio.h>

//#define DEBUG1
//#define DEBUG2
//#define DEBUGF

#include<stdio.h>
#define max(x,y)(x<y?y:x)
int main() {
	static int N, i, j, k, ans, A[100005], B[100005];
	scanf("%d", &N);
	for (i; i<N; ++i) {
		scanf("%d", &A[i]);
		if (B[A[i]]) {
			ans = max(ans, i - j);
			while (B[A[i]])
				B[A[j++]] = 0;
		}
		B[A[i]] = 1;//0?1???
	}
	ans = max(ans, i - j);
	printf("%d\n", ans);

#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^