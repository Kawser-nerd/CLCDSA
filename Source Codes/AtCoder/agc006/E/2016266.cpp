// O(N^2) solution
#include <string>
#include <iostream>
using namespace std;
int n, a[3][100009], p[100009], dr[100009];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j]; a[i][j]--;
		}
	}
	bool flag = true;
	for (int i = 0; i < n; i++) {
		p[i] = a[0][i] / 3;
		if (a[1][i] < p[i] * 3 || a[1][i] > p[i] * 3 + 2 || a[2][i] < p[i] * 3 || a[2][i] > p[i] * 3 + 2) flag = false;
		else if (a[0][i] < a[1][i] && a[1][i] < a[2][i]) dr[i + 2] = 0;
		else if (a[0][i] > a[1][i] && a[1][i] > a[2][i]) dr[i + 2] = 1;
		else flag = false;
		if (i % 2 != p[i] % 2) flag = false;
	}
	for (int i = 0; i < n; i++) dr[i] ^= dr[i + 2];
	if (!flag) cout << "No\n";
	else {
		for (int i = 0; i < n; i++) {
			int pos = -1;
			for (int j = i; j < n; j += 2) {
				if (p[j] == i) {
					pos = j;
					break;
				}
			}
			for (int j = pos - 2; j >= i; j -= 2) p[j + 2] = p[j];
			dr[i] ^= 1; dr[i + 2] ^= 1;
			dr[pos] ^= 1; dr[pos + 2] ^= 1;
			dr[i + 1] ^= 1; dr[pos + 1] ^= 1;
			p[i] = i;
		}
		for (int i = 0; i < n; i++) dr[i + 2] ^= dr[i];
		int ac = 0, bc = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) ac ^= dr[i];
			else bc ^= dr[i];
		}
		cout << (ac + bc ? "No\n" : "Yes\n");
	}
	return 0;
}