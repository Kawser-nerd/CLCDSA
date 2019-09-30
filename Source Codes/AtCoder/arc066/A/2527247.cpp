#include <map>
#include <iostream>

using namespace std;


typedef long long LL;


const LL MOD = 1000000007;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main() {
	LL ans = 1;
	int N;
	cin >> N;
	map<int,int> mp;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		mp[tmp]++;
	}

	bool flag = true;
	int i = 0;
	if(N % 2 == 1) {
		mp[0]++;
		for (auto&& var : mp) {
			if(var.first != i || var.second != 2 || var.first > N) {
				flag = false;
				break;
			}
			i += 2;
		}
	}
	else {
		i = 1;
		for (auto&& var : mp) {
			if (var.first != i || var.second != 2 || var.first > N) {
				flag = false;
				break;
			}
			i += 2;
		}
	}

	if (flag) {
		for (int i = 0; i < N/2; i++) {
			ans = ans*2;
			ans = ans % MOD;
		}
		cout << ans << endl;
	}

	else {
		cout << 0 << endl;
	}

	return 0;
}