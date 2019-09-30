#include <iostream>
#include <map>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<long long, int> mp;
	long long sum = 0;
	mp[0]++;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		sum += a;
		mp[sum]++;
	}
	long long ans = 0;
	for (auto &x : mp)
		ans += (x.second - 1ll) * x.second / 2;
	cout << ans << endl;
}