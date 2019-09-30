#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
int n, m;
bool b[50];
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)b[i] = 1;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		bool b1[50];
		for (int i = 1; i <= m; i++)b1[i] = 0;
		for (int j = 0; j < k; j++) {
			int p; cin >> p;
			b1[p] = 1;
		}
		for (int i = 1; i <= m; i++)if (!b1[i])b[i] = 0;
	}
	int cnt = 0;
	for (int i = 1; i <= m; i++)cnt += b[i];
	cout << cnt << endl;
}