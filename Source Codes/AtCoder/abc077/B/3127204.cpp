#include <iostream>
#include <math.h>
using namespace std;

inline bool Is_sqr(int n) {
	bool flg = false;

	for (int i = sqrt(n); i >= 1; i--)
	{
		if (i*i == n) {
			flg = true;
			break;
		}
	}

	return flg;
}

int main() {
	int n;
	int ans;
	cin >> n;

	for (int i = n; i >= 1; i--)
	{
		if (Is_sqr(i)) {
			ans = i;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}