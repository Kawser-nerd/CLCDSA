#include <cstdio>
#include <algorithm>

typedef long long LL;
const int N = 200005;
int n, k; LL a[N], b[N], sum[N], ans;

int read() {
	int x = 0; char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x;
}
int find(LL x) {
	int l = 1, r = n;
	while (l <= r) {
		int mid = l + (r - l >> 1);
		if (a[mid] == x) return mid;
		if (a[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
}
int lowbit(int x) {
	return x & (-x);
}
int query(int x) {
	int res = 0;
	while (x) res += b[x], x -= lowbit(x);
	return res;
}
void update(int x) {
	while (x <= n) ++b[x], x += lowbit(x);
}

int main() {
	n = read(), k = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = sum[i] = sum[i-1] + read() - k;
		if (sum[i] >= 0) ++ans;
	}
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		int x = find(sum[i]);
		ans += query(x); update(x);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.cpp:20:20: warning: operator '>>' has lower precedence than '-'; '-' will be evaluated first [-Wshift-op-parentheses]
                int mid = l + (r - l >> 1);
                               ~~^~~ ~~
./Main.cpp:20:20: note: place parentheses around the '-' expression to silence this warning
                int mid = l + (r - l >> 1);
                                 ^
                               (    )
./Main.cpp:25:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
2 warnings generated.