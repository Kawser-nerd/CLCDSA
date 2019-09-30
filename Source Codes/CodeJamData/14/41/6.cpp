#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		printf("Case #%d: ", nc);
		int n, X;
		cin >> n >> X;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		multiset<int> S(a.begin(), a.end());
		int ans = 0;
		while (!S.empty()) {
			int u = *S.rbegin();
			++ans;
			S.erase(S.find(u));
			if (S.empty())
				break;
			multiset<int>::iterator it = S.upper_bound(X - u);
			if (it != S.begin()) {
				int v = *--it;
				S.erase(S.find(v));
			}
		}
		printf("%d\n", ans);
	}
}
