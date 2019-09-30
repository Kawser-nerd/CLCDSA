#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
	int n; cin >> n;
	int a[114514];
	int ans = 0;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		int j = i;
		while (a[j + 1] == a[i] && j <= n)j++;
		int k = j - i + 1;
		if (k != a[i]) {
			if (k > a[i])ans += k - a[i];
			else ans += k;
		}
		i = j;
	}
	cout << ans << endl;
}