#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <vector>
using namespace std;
const int MAX_N = 1000 + 10;
int a[MAX_N], n;
int at[MAX_N];

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		printf("Case #%d: ", nc);
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		int ans = 0;
		while (!a.empty()) {
			int x = min_element(a.begin(), a.end()) - a.begin();
			ans += min(x, (int) a.size() - 1 - x);
			a.erase(a.begin() + x);
		}
		cout << ans << endl;
	}
}
