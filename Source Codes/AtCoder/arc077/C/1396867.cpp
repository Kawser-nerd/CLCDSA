#include<stdio.h>
#include<utility>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;
#define int long long

int a[100000], n, m;
ll sum[300000];
ll sum2[300000];
ll e[300000];
int dist(int a, int b) {
	return (b >= a ? b - a : b + m - a);
}
int dist(int a, int b, int c) {
	int A = dist(a, b), B = 1 + dist(c, b);
	return (A < B ? A : B);
}
signed main() {
	scanf("%lld%lld", &n, &m);
	rep(i, n)scanf("%lld", &a[i]), a[i]--;
	rep(i, n - 1) {
		if (a[i] < a[i + 1]) {
			sum[a[i] + 1]++;
			sum[a[i + 1] + 1]--;
			e[a[i + 1] + 1] -= a[i + 1] - a[i];
		}
		else {
			sum[a[i] + 1]++;
			sum[a[i + 1] + m + 1]--;
			e[a[i + 1] + m + 1] -= a[i + 1] + m - a[i];
		}
	}
	for (int i = 1; i <= 200005; i++)sum[i] += sum[i - 1];
	for (int i = 1; i <= 200005; i++)sum2[i] = sum2[i - 1] + e[i] + sum[i];
	ll id = 0, Max = 0;
	rep(i, m) {
		if (sum2[i] + sum2[i + m] > Max) {
			id = i; Max = sum2[i] + sum2[i + m];
		}
	}
	ll ans = 0;
	rep(i, n - 1) {
		ans += dist(a[i], a[i + 1], id);
	}
	printf("%lld\n", ans);
}