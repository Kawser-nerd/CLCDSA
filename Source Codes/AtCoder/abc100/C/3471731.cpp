#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int lli;

int main() {
	int N;
	vector<lli> a;
	cin >> N;
	lli ans;
	for(int i=1; i<=N; i++) {
		lli ai;
		cin >> ai;
		while(ai % 2 == 0) {
			ans++;
			ai /= 2;
		}
	}
	cout << ans << endl;
}