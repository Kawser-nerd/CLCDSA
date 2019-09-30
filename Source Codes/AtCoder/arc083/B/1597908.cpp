#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <vector>
#define int long long
using namespace std;
typedef tuple<int, int, int> T;

int n;
int a[300][300];
int b[300][300];

signed main() {
	int i, j, k;
	
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}
	
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] != b[i][j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	
	//????(i, j)???????a[i][j]???????, ???a[i][j]??????????
	int ans = 0;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			int minCost = 1145141919810893;
			for (k = 0; k < n; k++) {
				if (k == i || k == j) continue;
				minCost = min(minCost, a[i][k] + a[k][j]);
			}
			if (minCost > a[i][j]) {
				ans += a[i][j];
			}
		}
	}
	cout << ans << endl;
	return 0;
}