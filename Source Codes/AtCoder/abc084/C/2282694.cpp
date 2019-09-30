#include<iostream>
#include<algorithm>
using namespace std;
int f1(int a, int b) {
	if (a%b != 0)a += b - (a%b);
	return a / b;
}
int main() {
	int n; cin >> n;
	int c[600], s[600], f[600];
	for (int i = 1; i < n; i++) 
		cin >> c[i] >> s[i] >> f[i];
	for (int i = 1; i < n; i++) {
		int t = 0;
		for (int j = i; j < n; j++) {
			if (t <= s[j])t = s[j];
			else t = f1(t - s[j], f[j])*f[j] + s[j];
			t += c[j];
		}
		cout << t << endl;
	}
	cout << 0 << endl;
	return 0;
}