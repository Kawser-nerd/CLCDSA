#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int arr[1000001];
static int idx[1000001];
static int wei[1000001];

static int cmp(const void* a, const void* b)
{
	int aa = *((const int*)a);
	int bb = *((const int*)b);

	return arr[bb] - arr[aa];
}

static void solve(const int n)
{
	int L, N, C;
	long long int t, res;
	int i, p;

	res = 0;

	scanf("%d %lld %d %d ", &L, &t, &N, &C);
	for (i = 0; i < C; i++) {
		scanf("%d ", &arr[i]);
		idx[i] = i;
		wei[i] = 0;
	}
	arr[C] = 0;
	wei[C] = 0;
	idx[C] = C;
	for (i = 0; i < N; i++) {
		int next = arr[i%C];
		if (res > t) {
			wei[i%C]++;
		} else
		if (res+next*2 > t) {
			// partial
			p = (res+next*2 - t)/2;
			arr[C]=p;
			wei[C]++;
		}
		res += next*2;
	}
	qsort(idx,C+1,sizeof(int),cmp);
	for (i = 0; N && i <= C; i++) {
		int j = idx[i];
		int w = (wei[j] > L) ? L : wei[j];
		//printf("[%d] %d %d %lld %d\n", i, arr[j], wei[j], res, L);
		L -= w;
		wei[j] -= w;
		res -= arr[j]*w;
	}

	printf("Case #%d: %lld\n", n, res);
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
