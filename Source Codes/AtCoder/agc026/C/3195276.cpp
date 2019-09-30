#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define int long long

signed main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	int ans = 0;
	map<string, int> mp;
	for (int msk = 0; msk < (1 << N); ++msk) {
		string red, blue;
		for (int i = 0; i < N; ++i) {
			if (msk & (1 << i))
				red += S[i];
			else
				blue += S[i];
		}
		++mp[red+' '+string(blue.rbegin(), blue.rend())];
	}
	for (int msk = 0; msk < (1 << N); ++msk) {
		string red, blue;
		for (int i = 0; i < N; ++i) {
			if (msk & (1 << i))
				red += S[N+i];
			else
				blue += S[N+i];
		}
		ans += mp[string(blue.rbegin(), blue.rend())+' '+red];
	}
	cout << ans << endl;
}