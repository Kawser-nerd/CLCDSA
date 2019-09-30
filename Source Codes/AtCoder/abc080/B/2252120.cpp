#include<iostream>
using namespace std;
typedef long long ll;
ll f(ll n) {
	ll ans = 0;
	while (n > 0) {
		ans += n % 10; n /= 10;
	}return ans;
}
int main() {
	ll n; cin >> n;
	cout << ((n%f(n) == 0) ? "Yes\n" : "No\n");
	return 0;
}