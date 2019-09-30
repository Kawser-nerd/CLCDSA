#include <iostream>
#include <string>
using namespace std;
using ll = long long;

const ll mod = 1e9+7;

int N;
string S;

ll ans = 1;

int main() {
	cin >> N >> S;
	
	for(int c='a';c<='z';++c) {
		ll cnt = 1;
		for(int i=0;i<N;++i) {
			if(S[i] == c)++cnt;
		}
		ans *= cnt;
		ans %= mod;
	}
	
	cout << ans-1 << endl;
	
	return 0;
}