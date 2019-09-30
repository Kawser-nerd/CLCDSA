#include<iostream>
using namespace std;
int main() {
	int n; cin >> n;
	int a[114514] = {};
	for (int i = 0; i < n; i++) { int k; cin >> k; a[k]++; }
	if (n % 2 == 1) {
		if (a[0] == 1) {
			for (int i = 2; i < (n - 1); i += 2) 
				if (a[i] != 2)goto heaven;
		}
		else goto heaven;
		long long ans = 1;
		for (int i = 0; i < (n - 1) / 2; i++) { ans *= 2; ans %= 1000000007; }
		cout << ans << endl;
	}
	else {
		for (int i = 1; i < n; i += 2) { if (a[i] != 2)goto heaven; }
		long long ans = 1;
		for (int i = 0; i < n / 2; i++) { ans *= 2; ans %= 1000000007; }
		cout << ans << endl;
	}
	return 0;
heaven:cout << "0\n"; return 0;
}