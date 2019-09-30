#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

char A[150][64], B[150][64], X[64];
char S[64];
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		int N, L;
		scanf("%d %d", &N, &L);
		for (int i = 0; i < N; i++) {
			scanf("%s", &A[i]);
			for (int j = 0; j < L; j++) A[i][j] -= '0';
		}
		for (int i = 0; i < N; i++) {
			scanf("%s", &B[i]);
			for (int j = 0; j < L; j++) B[i][j] -= '0';
		}

		int answer = -1;
		for (int i = 0; i < N; i++) {
			// A[0] to B[i]
			int sol = 0;
			for (int j = 0; j < L; j++) {
				X[j] = A[0][j] ^ B[i][j];
				sol += X[j];
			}

			vector<string> C1, C2;
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < L; k++) {
					S[k] = (A[j][k] ^ X[k]) + '0';
				}
				S[L] = '\0';
				C1.push_back(S);
				for (int k = 0; k < L; k++) {
					S[k] = B[j][k] + '0';
				}
				C2.push_back(S);
			}
			sort(C1.begin(), C1.end());
			sort(C2.begin(), C2.end());
			bool diff = false;
			for (int i = 0; i < N; i++) {
				if (C1[i] != C2[i]) {
					diff = true;
					break;
				}
			}
			if (!diff) {
				if (answer == -1 || answer > sol)
					answer = sol;
			}
		}
		static int cs = 1;
		printf("Case #%d: ", cs++);
		if (answer < 0) printf("NOT POSSIBLE");
		else printf("%d", answer);
		printf("\n");
	}
	return 0;
}