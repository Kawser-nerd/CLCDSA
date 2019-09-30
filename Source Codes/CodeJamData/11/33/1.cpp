#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;
int T, N;
long long L, H;
long long notes[10005];
long long gcd(long long a, long long b) {
	return (b == 0 ? a : gcd(b, a % b));
}
long long find(long long l, long long n) {
	long long res;
	if (n == 0)
		return l;
	if (l == 0)
		return 1;
	for (res = l; res <= n / res; res ++)
		if (n % res == 0)
			return res;
	for (res = min(n / l, (long long)(sqrt(n) + 0.5)); res >= 1; res --)
		if (n % res == 0 && n / res >= l)
			return n / res;
	return -1;
}
long long check(int s) {
	int i, j;
	long long cnt = 1;
	if (s != 0 && s != N && notes[s] % notes[s - 1] != 0)
		return -1;
	for (i = 0; i < s; i ++) {
		long long tmp = cnt / gcd(cnt, notes[i]);
		if (tmp > notes[s] / notes[i] + 1)
			return -1;
		cnt = tmp * notes[i];
		if (cnt > notes[s] || cnt > H)
			return -1;
	}
	long long cnt2 = 0;
	for (; i < N; i ++) {
		cnt2 = gcd(cnt2, notes[i]);
		if (cnt2 % cnt != 0 || cnt2 < L)
			return -1;
	}
	cnt2 /= cnt;
	long long Low = (L + cnt - 1) / cnt;
	long long tmp = find(Low, cnt2);
	if (tmp != -1) {
		tmp *= cnt;
		if (tmp <= H)
			return tmp;
	}
	return -1;
}
int main() {
	int i, j, Case = 1;
	scanf("%d", &T);
	while (T --) {
		scanf("%d%I64d%I64d", &N, &L, &H);
		printf("Case #%d: ", Case ++);
		for (i = 0; i < N; i ++)
			scanf("%I64d", &notes[i]);
		sort(notes, notes + N);
		for (i = 0; i < N - 1; i ++)
			if (notes[i] == notes[i + 1]) {
				memmove(notes + i, notes + i + 1, sizeof(long long) * (N - i - 1));
				N --;
				i --;
			}
		notes[N] = H;
		long long res = -1;
		for (i = 0; i <= N; i ++)
			if ((res = check(i)) != -1)
				break;
		if (res != -1 && res <= H)
			printf("%I64d\n", res);
		else
			printf("NO\n");
	}
	return 0;
}
