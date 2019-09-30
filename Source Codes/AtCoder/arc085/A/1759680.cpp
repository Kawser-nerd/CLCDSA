#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	long long ans;
	ans = (n - m) * 100 + m * 1900;
	for (int i = 0; i < m; i++)ans *= 2;
	cout << ans << endl;
	char c; cin >> c;
}