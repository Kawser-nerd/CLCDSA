#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<list>
#include<queue>
#include<string.h>
#include<functional>
#include<stack>
#include<deque>
#include<string>
#include<limits.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;

inline int f(int l, int r, int k) {//????????????
	int a = r - l + 1;//??
	if (k < l) {
		return (l - k)*a + (a - 1)*a / 2;
	}
	if (k > r) {
		return (k - r)*a + (a - 1)*a / 2;
	}
	return (r - k)*(r - k + 1) / 2 + (k - l)*(k - l + 1) / 2;
}
signed main() {
	int ans = 1 << 29;
	int R, G, B; cin >> R >> G >> B;
	for (int i = -300; i <= 150; i++) {//??????????
		for (int j = max(-150, i + 1); j <= 300; j++) {//???????????
			if (j - i - 1 < G)continue;
			int sum = 0;
			int MIN = 1 << 29;
			for (int r = i; r >= i - 500; r--) {
				MIN = min(MIN, f(r - R + 1, r, -100));
			}
			sum += MIN;
			MIN = 1 << 29;
			for (int r = i + G; r < j; r++) {
				MIN = min(MIN, f(r - G + 1, r, 0));
			}
			sum += MIN;
			MIN = 1 << 29;
			for (int l = j; l <= j + 500; l++) {
				MIN = min(MIN, f(l, l + B - 1, 100));
			}
			sum += MIN;
			ans = min(ans, sum);
		}
	}
	cout << ans << endl;
}