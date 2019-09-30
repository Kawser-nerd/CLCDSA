#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
int n, a[10];
signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p; cin >> p;
		if (p < 400)a[0]++;
		else if (p < 800)a[1]++;
		else if (p < 1200)a[2]++;
		else if (p < 1600)a[3]++;
		else if (p < 2000)a[4]++;
		else if (p < 2400)a[5]++;
		else if (p < 2800)a[6]++;
		else if (p < 3200)a[7]++;
		else a[8]++;
	}
	int cnt = 0;
	for (int i = 0; i < 8; i++)if (a[i])cnt++;
	cout << max(cnt, (int)1) << ' ' << cnt + a[8] << endl;

}