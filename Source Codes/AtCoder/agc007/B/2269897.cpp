#include<iostream>
using namespace std;
int main() {
	int n; cin >> n;
	unsigned long long a[20010], b[20010];
	for (int i = 1; i <= n; i++) {
		a[i] = 30000 * i;
		b[n + 1 - i] = a[i];
	}
	for (int i = 0; i < n; i++) {
		int p; cin >> p;
		a[p] += i;
		b[p] += i;
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i];
		if (i == n)cout << endl; else cout << ' ';
	}
	for (int i = 1; i <= n; i++) {
		cout << b[i];
		if (i == n)cout << endl; else cout << ' ';
	}
	return 0;
}