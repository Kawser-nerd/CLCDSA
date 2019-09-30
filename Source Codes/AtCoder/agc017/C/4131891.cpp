#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> a(N), c(N + 1), s(N + 1);
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		++c[a[i]];
		if (a[i] - c[a[i]] >= 0) {
			if (s[a[i] - c[a[i]]] == 0) {
				++ans;
			}
			++s[a[i] - c[a[i]]];
		}
	}
	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y; --x;
		if (a[x] - c[a[x]] >= 0) {
			if (s[a[x] - c[a[x]]] == 1) {
				--ans;
			}
			--s[a[x] - c[a[x]]];
		}
		--c[a[x]];
		a[x] = y;
		++c[a[x]];
		if (a[x] - c[a[x]] >= 0) {
			if (s[a[x] - c[a[x]]] == 0) {
				++ans;
			}
			++s[a[x] - c[a[x]]];
		}
		cout << N - ans << '\n';
	}
	return 0;
}