#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long int sum[n + 1];
	sum[0] = 0LL;
	for(int i = 0; i < n; i++) {
		sum[i + 1] = sum[i] + a[i];
	}

	map<long long int,long long int> m;
	long long int ans = 0LL;
	
	for(int i = 0; i < n+1; i++) {
		ans += m[sum[i]];
		m[sum[i]] = m[sum[i]]+1LL;
	}
	cout << ans << endl;

}