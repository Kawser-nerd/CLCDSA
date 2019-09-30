#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include <random>
using namespace std;

int N;
int b[100], b_c[100];
int ans[100];
int ok;

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
		b_c[i] = b[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			if (b[j]-1 >= j) {
				ans[N-1-i] = j;
			}

		}
		for (int j = ans[N-1-i]; j < N - i - 1; j++) {
			b[j] = b[j + 1];
		}
		for (int j = 0; j < N - i - 1; j++) {
		}
	}

	for (int i = 0; i < N; i++) {
		/*i????ans[i] + 1?ans[i]?????????
		b[i-1] = b[i];
		b[ans[i]+1] = b[ans[i]]
		b[ans[i]] = ans[i]+1*/
		for (int j = i - 1; j >= ans[i] + 1;j--) {
			b[j] = b[j-1];
		}
		b[ans[i]] = ans[i] + 1;
	}

	ok = 1;
	for (int i = 0; i < N; i++) {
		if (b[i] != b_c[i]) {
			ok = 0;
		}
	}


	if (ok == 0) {
		printf("-1\n");
	}
	else {
		for (int i = 0; i < N; i++) {
			printf("%d\n", ans[i] + 1);
		}
	}
}