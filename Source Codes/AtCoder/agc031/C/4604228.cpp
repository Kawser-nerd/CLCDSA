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

int N, A, B;
int x;
int x_sum;
int P[200000], Q[200000];
int max_num;
int diff[20], same[20];
int main(void) {
	scanf("%d %d %d", &N, &A, &B);
	x = A ^ B;
	x_sum = 0;
	for (int i = 0; i < N; i++) {
		x_sum += x % 2;
		x = x / 2;
	}
	if (x_sum % 2 == 0) {
		printf("NO\n");
		return 0;
	}
	else {
		printf("YES\n");
	}
	int p = 0; int q = 0;
	int A2 = A;
	int B2 = B;
	for (int i = 0; i < N; i++) {
		if (A2 % 2 != B2 % 2) {
			diff[p] = i;
			p += 1;
		}
		else {
			same[q] = i;
			q += 1;
		}
		A2 = A2 / 2;
		B2 = B2 / 2;
	}

	//printf("x_sum=%d\n", x_sum);

	/*x_sum??????N-x_sum???? */
	max_num = 2;
	P[0] = 0;
	P[1] = 1;

	for (int i = 0; 2 * i + 1 < x_sum; i++) {
		max_num = max_num * 4;
		for (int j = 0; j < max_num / 2; j++) {
			if (j % 4 == 0 || j % 4 == 3) {
				Q[j] = 0;
			}
			else {
				Q[j] = 1;
			}
			Q[j] = Q[j] << (2 * i+1);
			Q[j] += P[j / 2];
		}
		for (int j = 0; j < max_num / 4; j++) {
			Q[max_num / 2 + j] = 2 << (2 * i+1);
			Q[max_num / 2 + j] += P[max_num / 4 - 1 - j];
		}
		for (int j = 0; j < max_num / 4; j++) {
			Q[max_num / 2 + max_num / 4 + j] = 3 << (2 * i+1);
			Q[max_num / 2 + max_num / 4 + j] += P[j];
		}
		for (int j = 0; j < max_num; j++) {
			P[j] = Q[j];
		}
	}

	for (int i = 0; i < N - x_sum; i++) {
		max_num = max_num * 2;
		for (int j = 0; j < max_num; j++) {
			if (j % 4 == 0 || j % 4 == 3) {
				Q[j] = 0;
			}
			else {
				Q[j] = 1;
			}
			Q[j] = Q[j] << (i + x_sum);
			Q[j] += P[j / 2];
		}
		for (int j = 0; j < max_num; j++) {
			P[j] = Q[j];
		}
	}
	for (int i = 0; i < max_num; i++) {
		Q[i] = 0;
		for (int j = 0; j < p; j++) {
			Q[i] += (P[i] % 2) << diff[j];
			P[i] = P[i] / 2;
		}
		for (int j = 0; j < q; j++) {
			Q[i] += (P[i] % 2) << same[j];
			P[i] = P[i] / 2;
		}
		printf("%d ", Q[i]^A);
	}
	printf("\n");
}