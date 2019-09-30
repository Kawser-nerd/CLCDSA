#include<iostream>
using namespace std;
typedef long long ll;
int main() {
	int n; ll l; cin >> n >> l;
	int ans = -1;
	ll b; cin >> b;
	for (int i = 1; i < n; i++) {
		ll a; cin >> a;
		if (b + a >= l)ans = i;
		b = a;
	}
	if (ans == -1)cout << "Impossible\n";
	else {
		cout << "Possible\n";
		for (int i = 1; i < ans; i++) cout << i << endl;
		for (int i = n - 1; i > ans; i--) cout << i << endl;
		cout << ans << endl;
	}
	return 0;
}