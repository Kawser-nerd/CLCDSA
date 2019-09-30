#include <stdio.h>
#include <string.h>

//A:AC
//int main() {
//	int x;
//	int ans=0;
//	
//	scanf("%d", &x);
//
//	ans = x / 10 + x % 10;
//
//	printf("%d\n", ans);
//
//	return 0;
//}

//B
//int main(void) {
//	int n;
//	char s[101];
//	int ans = -1;
//	int ngflg = 0;
//	int len, i;
//
//	scanf("%d", &n);
//	scanf("%s", s);
//
//	len = strlen(s);
//	if (len % 2 == 0) { ngflg = 1; }//????NG
//	if (len == 1 && s[0] == 'b') { ans = 0; }//b??
//	if (ngflg != 1 && ans != 0) {
//		i = 0;
//		if (len % 6 == 3) {//a**???
//			while (i < len) {
//				if (s[i] != 'a' && (i + 1) % 3 == 1) { ngflg = 1; }
//				i++;
//				if (i == len) { break; }
//				if (s[i] != 'b' && (i + 1) % 3 == 2) { ngflg = 1; }
//				i++;
//				if (i == len) { break; }
//				if (s[i] != 'c' && (i + 1) % 3 == 0) { ngflg = 1; }
//				i++;
//				if (i == len) { break; }
//			}
//		}
//		if (len % 6 == 1) {//b**???
//			while (i < len) {
//				if (s[i] != 'b' && (i + 1) % 3 == 1) { ngflg = 1; }
//				i++;
//				if (i == len) { break; }
//				if (s[i] != 'c' && (i + 1) % 3 == 2) { ngflg = 1; }
//				i++;
//				if (i == len) { break; }
//				if (s[i] != 'a' && (i + 1) % 3 == 0) { ngflg = 1; }
//				i++;
//				if (i == len) { break; }
//			}
//		}
//		if (len % 6 == 5) {//a**???
//			while (i < len) {
//				if (s[i] != 'c' && (i + 1) % 3 == 1) { ngflg = 1; }
//				i++;
//				if (i == len) { break; }
//				if (s[i] != 'a' && (i + 1) % 3 == 2) { ngflg = 1; }
//				i++;
//				if (i == len) { break; }
//				if (s[i] != 'b' && (i + 1) % 3 == 0) { ngflg = 1; }
//				i++;
//				if (i == len) { break; }
//			}
//		}
//	}
//	if (ngflg == 1) { ans = -1; }
//	else { ans = (len - 1) / 2; }
//
//	printf("%d\n", ans);
//	return 0;
//}

//c
//int y[100000] = { 0 }, x[100000] = { 0 };
//int r[100000] = { 0 }, c[100000] = { 0 };
//int yr[100000] = { 0 }, xc[100000] = { 0 };
//int yrp[100000] = { 0 }, xcp[100000] = { 0 };
//
//int main() {
//	int R, C, K, N, Y, X;
//	int cnt = 0;
//	int cntp = 0;
//	int cnt_and = 0;
//	int cntp_and = 0;
//	//int ans = 0;
//	long long ans = 0;
//
//	scanf("%d%d%d%d", &R, &C, &K, &N);
//	for (int i = 1; i < N + 1; i++) {
//		scanf("%d%d", &Y, &X);
//		y[i] = Y; x[i] = X;
//		r[Y]++; c[X]++;
//	}
//
//	for (int i = 1; i < R + 1; i++) {
//		for (int j = 1; j < C + 1; j++) {
//			if (K == r[i] + c[j]) {	//??k???????????
//				cnt++;
//				yr[cnt] = i;
//				xc[cnt] = j;
//				//printf("yr[%d]=%d  ",cnt, i);
//				//printf("yc[%d]=%d\n", cnt, j);
//			}
//			if (K+1 == r[i] + c[j]) {	//??k+1???????????
//				cntp++;
//				yrp[cntp] = i;
//				xcp[cntp] = j;
//				//printf("yrp[%d]=%d  ", cntp, i);
//				//printf("ycp[%d]=%d\n", cntp, j);
//			}
//		}
//	}
//
//	//??K?????????????????????
//	for (int i = 1; i < N + 1; i++) {
//		for (int j = 1; j < (R*C+1); j++) {
//			if (y[i] == yr[j] && x[i] == xc[j]) {
//				cnt_and++;
//				//printf("cnt_and = %d\n",cnt_and);
//			}
//		}
//	}
//	//??K+1?????????????????????
//	for (int i = 1; i < N + 1; i++) {
//		for (int j = 1; j < (R*C + 1); j++) {
//			if (y[i] == yrp[j] && x[i] == xcp[j]) {
//				cntp_and++;
//				//printf("cntp_and = %d\n", cntp_and);
//			}
//		}
//	}
//	//printf("????\n");
//	//printf("cnt = %d\n", cnt);
//	//printf("cnt_and = %d\n", cnt_and);
//	//printf("cntp_and = %d\n", cntp_and);
//	ans = cnt - cnt_and + cntp_and;
//	printf("%d\n", ans);
//		return 0;
//}

//C
#include <stdio.h>

int a[112345];
int b[112345];
int c[112345];
int r[112345];
int RK[112345];
int CK[112345];

int main(void) {

	int R, C, K;
	int N;

	scanf("%d %d %d", &R, &C, &K);
	scanf("%d", &N);

	int i;
	/*int a[N];
	int b[N];
	int c[C];
	int r[R];
	int RK[K+1];
	int CK[K+1];
	*/

	for (i = 0; i < C; i++) {
		c[i] = 0;
	}

	for (i = 0; i < R; i++) {
		r[i] = 0;
	}

	for (i = 0; i <= K; i++) {
		RK[i] = 0;
		CK[i] = 0;
	}

	for (i = 0; i < N; i++) {
		scanf("%d %d", a + i, b + i);
		r[a[i] - 1]++;
		c[b[i] - 1]++;
	}


	for (i = 0; i < C; i++) {
		if (c[i] <= K) CK[c[i]]++;
	}

	for (i = 0; i < R; i++) {
		if (r[i] <= K) RK[r[i]]++;
	}



	long long ans = 0;

	for (i = 0; i <= K; i++) {
		//printf("%d %d\n", CK[i], RK[K-i]);
		ans += CK[i] * RK[K - i];
	}

	//printf("%d\n", ans);

	for (i = 0; i < N; i++) {
		if (r[a[i] - 1] + c[b[i] - 1] == K) ans--;
		if (r[a[i] - 1] + c[b[i] - 1] == K + 1) ans++;
	}



	printf("%lld\n", ans);

	return 0;

} ./Main.c: In function ‘main’:
./Main.c:164:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &R, &C, &K);
  ^
./Main.c:165:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:190:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", a + i, b + i);
   ^