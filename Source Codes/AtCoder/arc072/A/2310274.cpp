#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n; cin >> n;
	long long ans1 = 0, cnt1 = 0, ans2 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		long long k; cin >> k;
		cnt1 += k; cnt2 += k;
		if (i % 2 == 0) {
			if (cnt1 <= 0) {
				ans1 += 1 - cnt1;
				cnt1 = 1;
			}
			if (cnt2 >= 0) {
				ans2 += 1 + cnt2;
				cnt2 = -1;
			}
		}
		else {
			if (cnt1 >= 0) {
				ans1 += 1 + cnt1;
				cnt1 = -1;
			}
			if (cnt2 <= 0) {
				ans2 += 1 - cnt2;
				cnt2 = 1;
			}
		}
	}
	cout << min(ans1, ans2) << endl;
	return 0;
}