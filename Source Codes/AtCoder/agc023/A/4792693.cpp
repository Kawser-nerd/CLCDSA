#include <iostream>
#include <vector>
#include <map>
typedef long long ll;

std::map<ll, ll> mp;

int main()
{
	ll n;
	std::vector<ll> arr(200005);

	ll ans = 0;

	std::cin >> n;
	for (ll i = 1; i <= n; i++) {
		std::cin >> arr[i];
	}

	mp[0] = 1;
	for (ll i = 1; i <= n; i++) {
		arr[i] = arr[i] + arr[i - 1];

		ans = ans + mp[arr[i]];
		mp[arr[i]]++;
	}

	std::cout << ans << std::endl;

	return 0;
}