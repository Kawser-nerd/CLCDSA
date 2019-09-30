#include<iostream>
using namespace std;
unsigned long long a[114514], b[114514];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	unsigned long long ans = 0;
	for (int i = n; i > 0; i--) {
		a[i] += ans;
		if (a[i] % b[i] != 0) {
			ans += b[i] - (a[i] % b[i]);
		}
	}
	cout << ans << endl;
	return 0;
}