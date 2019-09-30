#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int r, c, d; cin >> r >> c >> d;
	int ans = 0;
	for (int i = 0; i < r; i++)for (int j = 0; j < c; j++) {
		int a; cin >> a;
		if ((i + j) <= d && (i + j) % 2 == d % 2)ans = max(ans, a);
	}
	cout << ans << endl;
	return 0;
}