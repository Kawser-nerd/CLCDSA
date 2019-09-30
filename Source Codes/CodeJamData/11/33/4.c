#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void solve(const int n)
{
	int N, L, H;
	int i, res;
	int arr[100];
	
	scanf("%d %d %d ", &N, &L, &H);
	for (i = 0; i < N; i++) {
		scanf("%d ", &arr[i]);
	}

	for (res = L; res <= H; res++) {
		int fail = 0;
		for (fail = 0, i = 0; !fail && i < N; i++) {
			int t = arr[i];
			if (t > res) {
				if (t % res != 0) fail = 1;
			} else {
				if (res % t != 0) fail = 1;
			}
		}
		if (!fail) goto ok;
	}

	printf("Case #%d: NO\n", n);
	return;
ok:
	printf("Case #%d: %d\n", n, res);
}

int main(int argc, char **argv)
{
	int T;
	int i;

	scanf("%d ", &T);
	for (i = 0; i < T; i++) {
		solve(i+1);
	}
	return 0;
}
