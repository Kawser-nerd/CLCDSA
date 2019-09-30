#include <cstdio>
#include <map>

using namespace std;

map<long long, long long> M;

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int T, Tn;
	scanf("%d", &Tn);
	for (T = 1; T <= Tn; T++) {
		long long n, m;
		scanf("%lld%lld", &n, &m);
		M.clear();
		M[n + 1] = 1;
		while (1) {
			auto t = prev(M.end());
			if (t->second >= m) {
				printf("Case #%d: %lld %lld\n", T, t->first - 1 >> 1, t->first - 2 >> 1);
				break;
			}
			m -= t->second;
			M[t->first + 1 >> 1] += t->second;
			M[t->first >> 1] += t->second;
			M.erase(t);
		}
	}
	return 0;
}
