#include <stdio.h>

int A[100005];
int dot[100005];

int main() {

	int N;

	scanf("%d",&N);

	int i;

	for (i = 0; i < N; i++) {
		scanf(" %d",&A[i]);
	}

	i = 0;

	while (1) {
		if (i >= N - 1) { break; }

		int cnt = 0;
		int start;
		while (1) {
			if (i >= N - 1) { break; }
			if (cnt == 0) {
				if (A[i] < A[i + 1]) {
					start = 0;
				}
				else if (A[i] > A[i + 1]) {
					start = 1;
				}
				else {
					while (1) {
						if (i >= N - 1 || A[i] != A[i + 1]) { break; }
						i++;
					}

					if(i<N-1){
						if (A[i] < A[i + 1]) {
							start = 0;
						}
						else if (A[i] > A[i + 1]) {
							start = 1;
						}
					}

				}
			}
			else {
				if (start == 0 && A[i] > A[i+1]) {
					dot[i] = 1;
					i++;
					break;
				}
				if (start == 1 && A[i] < A[i + 1]) {
					dot[i] = 1;
					i++;
					break;
				}
			}
			cnt++;
			i++;
		}


	}

	int ans = 1;
	for (i = 0; i < N - 1; i++) {
		if (dot[i] == 1) { ans++; }
	}

	printf("%d\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %d",&A[i]);
   ^