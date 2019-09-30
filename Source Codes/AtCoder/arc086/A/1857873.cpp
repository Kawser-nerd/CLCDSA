#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, k; cin >> n >> k;
	int a[200010] = {};
	for (int i = 0; i < n; i++) {
		int p; cin >> p; a[p]++;
	}
	sort(a, a + 200001);
	int ans = 0;
	for (int i = 200000 - k; a[i] > 0; i--)ans += a[i];
	cout << ans << endl;
}