#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> mp;

int main()
{
	long long n;
	vector<long long> vec(2 * 100005);
	long long ans = 0;

	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> vec[i];
	}

	mp[0] = 1;
	for (long long i = 1; i <= n; i++) {
		vec[i] += vec[i - 1];

		ans = ans + mp[vec[i]];
		mp[vec[i]]++;
	}

	cout << ans << endl;

	return 0;
}