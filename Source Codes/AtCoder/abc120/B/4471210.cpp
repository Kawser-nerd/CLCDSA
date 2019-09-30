#include <iostream>
#include <vector>
#define int long long
using namespace std;
signed main() {
	int a, b, k; cin >> a >> b >> k;
	vector<int>v;
	for (int i = 1; i <= 100; i++) {
		if (a%i == 0 && b%i == 0) {
			v.push_back(i);
		}
	}
	cout << v[v.size() - k] << endl;
}